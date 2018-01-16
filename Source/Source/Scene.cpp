#include "Scene.h"


Scene::Scene(void)
{
	this->listGameObject = std::vector<GameObject*>();
	this->m_name = "";
}

Scene::Scene(std::string pathFile)
{
	this->m_pathFile = pathFile;
	LoadDataFromFile();
}


Scene::~Scene(void)
{

}

std::string Scene::GetName()
{
	return this->m_name;
}

std::vector<GameObject*> Scene::GetListGameObject()
{
	return this->listGameObject;
}

GameObject* Scene::GetGameObjectByName(std::string name)
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

void Scene::LoadDataFromFile()
{
	// TODO : Charger tous les GameObject provenant du fichier, ainsi que le nom de la scene
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
								go = new GameObject(r.second.data());
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
										Component* component = new Component(NULL);
										BOOST_FOREACH(ptree::value_type const& b, l.second.get_child(""))
										{
											if (b.first == "type")
											{
												component->SetType(b.second.data());
											}
										}
										go->AddComponent(component);
									}
								}
							}
						}
					}

					this->AddGameObject(go);
					int dssd = 0;
				}
			}
		}
	}
}

void Scene::AddGameObject(GameObject* go)
{
	this->listGameObject.push_back(go);
}