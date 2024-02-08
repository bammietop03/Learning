#!/usr/bin/python3

import json
from models.base_model import BaseModel
from models.user import User
from models.place import Place
from models.state import State
from models.city import City
from models.amenity import Amenity
from models.review import Review

class FileStorage:
    __file_path = 'file.json'
    __objects = {}

    def all(self, cls=None):
        if cls is None:
            return FileStorage.__objects
        else:
            filtered_objs = {}
            for key, obj in self.__objects.items():
                if isinstance(obj, cls):
                    filtered_objs[key] = obj
            return filtered_objs

    def new(self, obj):
        """Sets in _objects the obj with key <obj class name>.id"""
        key = f"{obj.__class__.__name__}.{obj.id}"
        self.__objects[key] = obj
    
    def save(self):
        """serializes __objects to the JSON file (path: __file_path)"""
        serialized = {}
        for key, obj in self.__objects.items():
            serialized[key] = obj.to_dict() 
        with open(self.__file_path, 'w', encoding='utf=8' ) as file:
            json.dump(serialized, file)

    def reload(self):
        """deserializes the JSON file to __objects (only if the JSON file (__file_path)"""
        try:
            with open(self.__file_path, 'r', encoding='utf=8') as file:
                data = json.load(file)
                for key, value in data.items():
                    obj = eval(value['__class__'])(**value)
                    self.__objects[key] = obj
        except FileNotFoundError:
            pass

    def delete(self, obj=None):
        """to delete obj from __objects if it’s inside - if obj is equal to None, the method should not do anything"""
        if obj is not None:
            key = obj.__class__.__name__ + '.' + obj.id
            if key in self.__objects:
                del self.__objects[key]