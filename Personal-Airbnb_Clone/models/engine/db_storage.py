#!/usr/bin/python3

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from os import environ

class DBStorage:
    __engine = None
    __session = None

    def __init__(self):

        db_user = environ.get('HBNB_MYSQL_USER')
        db_pwd = environ.get('HBNB_MYSQL_PWD')
        db_host = environ.get('HBNB_MYSQL_HOST')
        db_name = environ.get('HBNB_MYSQL_DB')

        self.__engine = create_engine('mysql+mysqlconnector://{}:{}@{}/{}'\
                                      .format(db_user, db_pwd, db_host, db_name), pool_pre_ping=True)
        
        if environ.get('HBNB_ENV') == 'test':
            Base.metadata.drop_all(self.__engine)