#!/usr/bin/python3
"""This will run before a new intance is created"""
from models.engine.file_storage import FileStorage

storage = FileStorage()
storage.reload()