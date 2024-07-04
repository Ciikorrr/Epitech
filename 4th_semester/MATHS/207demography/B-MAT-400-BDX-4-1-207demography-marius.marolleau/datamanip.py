#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Get the datas from the csv
"""

_file_name = "207demography_data.csv"
_country_datas = {}
_country_code_to_country = {}
_year_range = range(1960, 2018)

def get_datas(file_name=_file_name, line_split="\n", separator=";"):
    with open(file_name, "r") as f:
        datas = f.read()
    lines = [d for d in datas.split(line_split) if d]
    datalistdict = []
    keys = lines[0].split(separator)
    for line in lines[1:]:
        datasplit = line.split(separator)
        if not len(datasplit) == len(keys):
            raise ValueError("some datas are missing")
        data = {k: v for k,v in zip(keys, datasplit)}
        datalistdict.append(data)
    construct_country_datas(datalistdict)
    return None

def construct_country_datas(datalistdict):
    global _country_datas, _country_code_to_country
    for datas in datalistdict:
        year_population = {}
        for year in _year_range:
            try:
                year_population[year] = int(datas[str(year)])
            except ValueError: # cannot convert to int
                pass
        _country_datas[datas['Country Name']] = year_population
        _country_code_to_country[datas['Country Code']] = datas['Country Name']
    if not len(_country_code_to_country) == len(_country_datas):
        raise ValueError("Missing country codes")
    return None

def get_datas_for_one_country_code(country_code="AZE"):
    return _country_datas[_country_code_to_country[country_code]]

get_datas()
