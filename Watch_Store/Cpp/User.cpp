#include <iostream>
#include "../Headers/User.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/ostreamwrapper.h"
#include "../include/rapidjson/istreamwrapper.h"
using namespace std;
using namespace rapidjson;

// the buyWatch method adds a chosen watch to the user's profile in the JSON file
void User::buyWatch(const string& username, const string& userPass, const string& brandName, const string& modelName, const string& description){
    string jsonFilePath = "JSON_Data/users.json";
    char c;

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }
    
    const auto& usersArray = document["users"];
    if (!usersArray.IsArray()) {
        throw runtime_error("Invalid JSON format in file: " + jsonFilePath);
    }

    // matching the user with its profile in the file
    for (rapidjson::SizeType i = 0; i < usersArray.Size(); ++i) {
        const auto& userData = usersArray[i];

        const auto& usernameValue = userData["username"];
        const auto& userPassValue = userData["userPass"];

        if (!usernameValue.IsString() || !userPassValue.IsString()){
            throw runtime_error("Invalid JSON data types in file: " + jsonFilePath);
        }

        if(usernameValue.GetString() == username && userPassValue.GetString() == userPass){
            Value& watchCollection = document["users"][i]["watchCollection"];

            if (!watchCollection.IsArray()){
                throw runtime_error("Invalid JSON format in file: " + jsonFilePath);
            }

            // when there is a match a new object is created
            // then it is added to the JSON file
            Value newWatch(kObjectType);
            newWatch.AddMember("brandName", StringRef(brandName.c_str()), document.GetAllocator());
            newWatch.AddMember("modelName", StringRef(modelName.c_str()), document.GetAllocator());
            newWatch.AddMember("description", StringRef(description.c_str()), document.GetAllocator());
            watchCollection.PushBack(newWatch, document.GetAllocator());
            
            ofstream ofs(jsonFilePath);
            OStreamWrapper osw(ofs);
            Writer<OStreamWrapper> writer(osw);
            document.Accept(writer);
            
            cout << "\nWatch " << brandName << " " << modelName << " bought successfully!" << endl;
            cout << "Press any letter to continue: ";
            cin >> c;
            return;
        }
    }
}

// the displayCollection method iterates through the user's watch collection
void User::displayCollection(const string& username, const string&userPass){
    string jsonFilePath = "JSON_Data/users.json";
    char c;

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }
    
    const auto& usersArray = document["users"];
    if (!usersArray.IsArray()){
        throw runtime_error("Invalid JSON format in file: " + jsonFilePath);
    }

    // matching the user credentials with the correct profile
    for (rapidjson::SizeType i = 0; i < usersArray.Size(); ++i) {
        const auto& userData = usersArray[i];

        const auto& usernameValue = userData["username"];
        const auto& userPassValue = userData["userPass"];

        if (!usernameValue.IsString() || !userPassValue.IsString()){
            throw runtime_error("Invalid JSON data types in file: " + jsonFilePath);
        }

        if(usernameValue.GetString() == username && userPassValue.GetString() == userPass){
            const auto& watchCollection = document["users"][i]["watchCollection"];

            if (!watchCollection.IsArray()){
                throw runtime_error("Invalid JSON format in file: " + jsonFilePath);
            }

            system("cls");
            cout << "\n\n\nWatch Collection:\n\n";
            
            // iterating through the watch collection in the particular element
            for(rapidjson::SizeType j = 0; j < watchCollection.Size(); ++j){
                const auto& watchData = watchCollection[j];

                const auto& brandNameValue = watchData["brandName"];
                const auto& modelNameValue = watchData["modelName"];
                const auto& descriptionValue = watchData["description"];

                if (!brandNameValue.IsString() || !modelNameValue.IsString() || !descriptionValue.IsString()){
                    throw runtime_error("Invalid JSON data types in file: " + jsonFilePath);
                }

                // printing the brand name, model name, and description of the watch
                cout << brandNameValue.GetString() << " " << modelNameValue.GetString() << "\n" << descriptionValue.GetString() << "\n\n";
            }

            cout << "\nPress any letter to continue: ";
            cin >> c;
            return;
        }
    }
}

// the createProfile method ask the user for credentials and then adds them to the JSON file as a account
void User::createProfile(){
    string username, userPass, jsonFilePath;
    char c;

    jsonFilePath = "JSON_Data/users.json";

    system("cls");
    cin.ignore();
    cout << "\n\n\nEnter username: ";
    getline(cin, username);
    cout << "\n\n\nEnter password: ";
    cin >> userPass;

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }

    // new object is created 
    Value newUser(kObjectType);
    Document::AllocatorType& allocator = document.GetAllocator();

    // the values are passed
    newUser.AddMember("username", StringRef(username.c_str()), allocator);
    newUser.AddMember("userPass", StringRef(userPass.c_str()), allocator);

    // an empty watch collection is added, so when a watch is bought, it will be stored there
    Value watchCollection(kArrayType);
    newUser.AddMember("watchCollection", watchCollection, allocator);

    Value& users = document["users"];
    if (!users.IsArray()) {
        users.SetArray();
    }

    // then the object is added to the file
    users.PushBack(newUser, allocator);

    ofstream ofs(jsonFilePath);
    if (!ofs.is_open()) {
        cerr << "Failed to open JSON file for writing: " << jsonFilePath << endl;
        cin >> c;
        return;
    }

    OStreamWrapper osw(ofs);
    Writer<OStreamWrapper> writer(osw);
    document.Accept(writer);

    cout << "\nUser added successfully to " << jsonFilePath << endl;
    cout << "Press any letter to continue: ";
    cin >> c;
}

// the loginProfile method matches the username and userPass given by the user to a profile in the file
bool User::loginProfile(const string& username, const string& userPass){
    string jsonFilePath = "JSON_Data/users.json";

    ifstream ifs(jsonFilePath);
    rapidjson::Document document;
    if (ifs.is_open()) {
        IStreamWrapper isw(ifs);
        document.ParseStream(isw);
        ifs.close();
    }
    
    // checking fo existence of users collection
    const auto& usersArray = document["users"];
    if (!usersArray.IsArray()) {
        throw runtime_error("Invalid JSON format in file: " + jsonFilePath);
    }

    // iterating through the file until a matching credentials are found
    for (rapidjson::SizeType i = 0; i < usersArray.Size(); ++i) {
        const auto& userData = usersArray[i];

        const auto& usernameValue = userData["username"];
        const auto& userPassValue = userData["userPass"];

        if (!usernameValue.IsString() || !userPassValue.IsString()){
            throw runtime_error("Invalid JSON data types in file: " + jsonFilePath);
        }
        
        // if a match is found then the user is logged into the program with their credentials
        // the credentials are later used in other methods like buying, and customizing watches
        if(usernameValue.GetString() == username && userPassValue.GetString() == userPass){
            return true;
        }
    }
    
    // if no match is found then the method returns false and the user will get a message saying: No profile found
    return false;
}