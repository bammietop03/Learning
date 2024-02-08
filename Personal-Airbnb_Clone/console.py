#!/usr/bin/python3

import cmd
import re
from models.base_model import BaseModel
from models.__init__ import storage
from models.user import User
from models.place import Place
from models.state import State
from models.city import City
from models.amenity import Amenity
from models.review import Review


class HBNBCommand(cmd.Cmd):
    prompt = "(hnhn) "

    class_names = {
               'BaseModel': BaseModel, 'User': User, 'Place': Place,
               'State': State, 'City': City, 'Amenity': Amenity,
               'Review': Review
              }
    
    def do_quit(self, arg):
        """Quit command to exit the program"""
        return True
    
    def do_EOF(self, arg):
        """EOF command to exit the program"""
        print()
        return True
    
    def precmd(self, arg):
        """
        if "update" in arg:
            class_id, rest_of_command = arg.split(None, 1)
            rest_of_command = rest_of_command.replace('"', '')
            return f"{class_id} {rest_of_command}"
        """
        if "." in arg and not 'create' in arg:
            new_str = re.sub(r'[){}:\'"]', "", arg)
            new_str = re.sub(r'[(.,]', " ", new_str).split()
            new_str[0], new_str[1] = new_str[1], new_str[0]
            arg = " ".join(new_str)
        return super().precmd(arg)
    
    def do_create(self, arg):
        """ creates a new instance of BaseModel or User, saves it
        (to the JSON file) and prints the id. Ex: $ create BaseModel
        """
        if not arg:
            print("** class name missing **")
        else:
            args = arg.split()
            if args[0] in self.class_names:
                new_instance = eval(args[0])()
                for param in args[1:]:
                    if '=' in param:
                        key, value = param.split('=')
                        if value.startswith('"') and value.endswith('"'):
                            value = value[1:-1].replace('_', ' ').replace('\\"', '"')
                        elif '.' in value:
                            value = float(value)
                        else:
                            value = int(value)
                        setattr(new_instance, key, value)

                new_instance.save()
                print(new_instance.id)
            else:
                print("** class doesn't exist **")

    def do_show(self, arg):
        """Prints the string representation of an instance based on the class
        name and id. Ex: $ show BaseModel 1234-1234-1234.
        """
        if not arg:
            print("** class name missing **")
        else:
            args = arg.split(" ")
            if args[0] not in self.class_names:
                print("** class doesn't exist **")
            elif len(args) < 2:
                print("** instance id missing **")
            else:
                key = args[0] + "." + args[1]

                if key in storage.all():
                    print(storage.all()[key])
                else:
                    print("** no instance found **")

    def do_destroy(self, arg):
        """Deletes an instance based on the class name and id (save the change
        into the JSON file). Ex: $ destroy BaseModel 1234-1234-1234.
        """
        if not arg:
            print("** class name missing **")
        else:
            args = arg.split(" ")
            if args[0] not in self.class_names:
                print("** class doesn't exist **")
            elif len(args) < 2:
                print("** instance id missing **")
            else:
                key = args[0] + "." + args[1]

                if key in storage.all():
                    del storage.all()[key]
                    storage.save()
                else:
                    print("** no instance found **")

    def do_all(self, arg):
        """Prints all string representation of all instances based or not on
        the class name. Ex: $ all BaseModel or $ all.
        """
        if not arg:
            for obj in storage.all().values():
                print(str(obj))
        else:
            args = arg.split()
            if args[0] not in self.class_names:
                print("** class doesn't exist **")
            else:
                for obj in storage.all().values():
                    if obj.__class__.__name__ == args[0]:
                        print(str(obj))

    def do_update(self, arg):
        """Updates an instance based on the class name and id by adding or
        updating attribute (save the change into the JSON file).
        Ex: $ update BaseModel 1234-1234-1234 email "aibnb@mail.com".
        """
        if not arg:
            print("** class name missing **")
        else:
            args = arg.split()
            if args[0] not in self.class_names:
                print("** class doesn't exist **")
            elif len(args) < 2:
                print("** instance id missing **")
            elif len(args) < 3:
                print("** attribute name missing **")
            elif len(args) < 4:
                print("** value missing **")

            else:
                key = args[0] + "." + args[1]
                if key in storage.all():
                    instance = storage.all()[key]
                    for i in range(2, len(args) - 1, 2):
                        if i + 1 < len(args):
                            attr_name = args[i]
                            attr_value = args[i + 1]
                            if attr_value.startswith('"') and attr_value.endswith('"'):
                                attr_value = attr_value[1:-1]

                            if attr_value.isdigit():
                                attr_value = int(attr_value)
                            else:
                                try:
                                    attr_value = float(attr_value)
                                except ValueError:
                                    pass
                            setattr(instance, attr_name, attr_value)
                        else:
                            break
                    instance.save()
                else:
                    print("** no instance found **")

    def do_count(self, arg):
        """Retrieves the number of instances of a specified class. 
        Usage: <class name>.count()"""
        args = arg.split()
        if not arg:
            print("** class name missing **")
        else:
            if args[0] not in self.class_names:
                print("** class doesn't exist **")
            else:
                count = 0
                for obj in storage.all().values():
                    if obj.__class__.__name__ == args[0]:
                        count += 1
                print(count)





if __name__ == "__main__":
    HBNBCommand().cmdloop()
