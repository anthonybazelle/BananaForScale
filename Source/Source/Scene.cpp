#include "Scene.h"


Scene::Scene(void)
{
	this->listGameObject = std::vector<GameObject*>();
	this->m_name = "";
	this->m_pathFile = "";
}

Scene::Scene(std::string pathFile)
{
	this->m_pathFile = pathFile;
	LoadDataFromFile();
}


Scene::~Scene(void)
{

}

void Scene::RemoveGameObject(GameObject* go)
{
	for (int i = 0; i < this->listGameObject.size(); ++i)
	{
		if (this->listGameObject[i] == go)
		{
			this->listGameObject.erase(this->listGameObject.begin() + i);
			break;
		}
	}
}

std::string Scene::GetName()
{
	return this->m_name;
}

std::vector<GameObject*> Scene::GetListGameObject()
{
	return this->listGameObject;
}

GameObject* Scene::GetGameObjectByName(std::string& name)
{
	try
	{
		for(auto it = this->listGameObject.begin(); it != this->listGameObject.end(); ++it)
		{
			if((*it)->GetName().compare(name) == 0)
			{
				return (*it);
			}
		}
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	return NULL;
}

void Scene::SetName(std::string name)
{
	this->m_name = name;
}

void Scene::SetPathFile(std::string path)
{
	this->m_pathFile = path;
}

std::string Scene::GetPathFile()
{
	return this->m_pathFile;
}

std::string Scene::CheckName(std::string name)
{
	bool isChecked = false;
	bool isChecked2 = true;
	int countSame = 1;

	while (!isChecked)
	{
		for (auto it = this->listGameObject.begin(); it != this->listGameObject.end(); ++it)
		{
			if ((*it)->GetName().compare(name) == 0)
			{
				isChecked2 = false;
				break;
			}
		}

		if (isChecked2)
			break;

		int indexOpen = 0;
		if ((indexOpen = name.find("(")) != std::string::npos)
		{
			int toIncrement = atoi(name.substr(indexOpen + 1, name.find(")") - indexOpen).c_str());
			std::string toReplace = "(" + std::to_string(toIncrement) + ")";
			name.replace(indexOpen, toReplace.length(), "(" + std::to_string(toIncrement + 1) + ")");
		}
		else
		{
			name = name + " (" + std::to_string(countSame) + ")";
		}

		++countSame;
		isChecked2 = true;
	}

	return name;
}

void Scene::LoadDataFromFile()
{
	// TODO : Charger tous les GameObject provenant du fichier, ainsi que le nom de la scene
	// TODO : Changer les else if pas beaux en switch, plus perf
	// juste pour les tests :
	if (m_pathFile.find("1") != std::string::npos)
	{
		this->m_name = "Tab 1";
	}
	else if (m_pathFile.find("2") != std::string::npos)
	{
		this->m_name = "Tab 2";
	}

	std::filebuf fb;
	if (fb.open(m_pathFile, std::ios::in))
	{
		std::istream is(&fb);
		using boost::property_tree::ptree;
		ptree pt;
		read_xml(is, pt);
		BOOST_FOREACH(ptree::value_type const& v, pt.get_child("Scene")) 
		{
			if (v.first == "name") 
			{
				this->m_name = v.second.data();
			}
			else if (v.first == "GameObjectList")
			{
				BOOST_FOREACH(ptree::value_type const& q,  pt.get_child("Scene").get_child("GameObjectList")) 
				{
					GameObject* go = NULL;
					if (q.first == "GameObject")
					{
						GameObject::Point pivot;

						BOOST_FOREACH(ptree::value_type const& r, q.second.get_child(""))
						{
							if (r.first == "name")
							{
								go = new GameObject(CheckName(r.second.data()));
							}
							if (r.first == "pivotX")
							{
								if (go != NULL)
								{
									pivot.x = atof(r.second.data().c_str());
								}
							}
							else if (r.first == "pivotY")
							{
								if (go != NULL)
								{
									pivot.y = atof(r.second.data().c_str());
								}
							}
							else if (r.first == "pivotZ")
							{
								if (go != NULL)
								{
									pivot.z = atof(r.second.data().c_str());
								}
							}
							else if (r.first == "ComponentList")
							{
								if (go != NULL)
								{
									go->SetPivot(pivot);
								}

								BOOST_FOREACH(ptree::value_type const& l, r.second.get_child(""))
								{
									if (l.first == "Component")
									{
										Component* component = new Component(go->GetListComponent().size());
										Component::Point p;
										p.x = 0.f, p.y = 0.f, p.z = 0.f;
										BOOST_FOREACH(ptree::value_type const& b, l.second.get_child(""))
										{
											if (b.first == "type")
											{
												component->SetType(b.second.data());
											}
											else if (b.first == "pivotX")
											{
												p.x = std::atof(b.second.data().c_str());
											}
											else if (b.first == "pivotY")
											{
												p.y = std::atof(b.second.data().c_str());
											}
											else if (b.first == "pivotZ")
											{
												p.z = std::atof(b.second.data().c_str());
												component->SetPosition(p.x, p.y, p.z);
											}
											else if (b.first == "rotateX")
											{
												component->rotateX = std::atof(b.second.data().c_str());
											}
											else if (b.first == "rotateY")
											{
												component->rotateY = std::atof(b.second.data().c_str());
											}
											else if (b.first == "rotateZ")
											{
												component->rotateZ = std::atof(b.second.data().c_str());
											}
										}
										go->AddComponent(component);
										CLog::getInstance()->Write("Scene - " + this->GetName() + "-- GameObject - " + go->GetName(), "Add Component", component->GetCompleteName());
									}
								}
							}
						}
					}
					CLog::getInstance()->Write("Scene - " + this->GetName(), "Add GO", go->GetName());
					this->AddGameObject(go);
				}
			}
		}
	}
}

void Scene::AddGameObject(GameObject* go)
{
	this->listGameObject.push_back(go);
}