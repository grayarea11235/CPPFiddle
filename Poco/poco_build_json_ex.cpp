#include <iostream>
#include <fstream>

#include <Poco/JSON/Object.h>

// From : https://pragmaticjoe.blogspot.com/2015/04/building-jsons-using-poco-c-library.html

Poco::JSON::Object::Ptr buildJSON()
{
    Poco::JSON::Object::Ptr root = new Poco::JSON::Object();
    Poco::JSON::Object::Ptr menuObj = new Poco::JSON::Object();
    menuObj->set("id", "file");
    menuObj->set("value", "File");

    //menuitem array
    Poco::JSON::Array::Ptr menuitemArray = new Poco::JSON::Array();

    //objects in array
    Poco::JSON::Object::Ptr arrObj1 = new Poco::JSON::Object();
    arrObj1->set("value", "New");
    arrObj1->set("onClick", "CreateNewDoc()");

    Poco::JSON::Object::Ptr arrObj2= new Poco::JSON::Object();
    arrObj2->set("value", "Open");
    arrObj2->set("onClick", "OpenDoc()");

    Poco::JSON::Object::Ptr arrObj3 = new Poco::JSON::Object();
    arrObj3->set("value", "Close");
    arrObj3->set("onClick", "CloseDoc()");

    menuitemArray->set(0, arrObj1);
    menuitemArray->set(1, arrObj2);
    menuitemArray->set(2, arrObj3);

    menuObj->set("menuitem", menuitemArray);

    root->set("menu", menuObj);

    return root;
}


int main(int argv, char *argc[])
{
  std::cout << "Starting\n";
  
  auto res = buildJSON();
  
  std::ostringstream oss;
  Poco::JSON::Stringifier::stringify(res, oss);
  std::ofstream ofs("output.json");
  if (ofs.is_open() == true)
  {
    ofs << oss.str();
    ofs.close();
  }
  
  return 0;
}
