#!/usr/bin/python3
"""
This module defines a City class thati inherits from BaseModel.

The City class represents a city and includes attributes for
the state ID and the city name.
"""
from models.base_model import BaseModel
from models.base_model import Base
from sqlalchemy import Column, String, ForeignKey 
import os

class City(BaseModel, Base):
    """City  class that inherits from BaseModel"""
    __tablename__ = 'cities'

    if os.getenv("HBNB_TYPE_STORAGE") == 'db':
        name = Column(String(128), nullable=False)
        state_id = Column(String(60), ForeignKey('states.id'), nullable=False)
    else:
        state_id = ""
        name = ""
