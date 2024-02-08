#!/usr/bin/python3
"""
This module defines a State class that inherits from BaseModel.

The State class represents a state and includes an attribute for
the state name.
"""
from models.base_model import BaseModel, Base
from models.city import City
import models
from sqlalchemy import Column, String, ForeignKey
from sqlalchemy.orm import Relationship 
import os


class State(BaseModel, Base):
    """State class that inherits from BaseModel."""
    __tablename__ = 'states'

    if os.getenv("HBNB_TYPE_STORAGE") == 'db':
        name = Column(String(128), nullable=False)
        cities = Relationship("City", cascade="all, delete-orphan", backref="state")
    else:
        name = ""

    @property
    def cities(self):
        cities_list = []
        for city in models.storage.all(City).values():
            if city.state_id == self.id:
                cities_list.append(city)
        return cities_list
