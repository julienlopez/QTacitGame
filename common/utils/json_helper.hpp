#pragma once

#include "externals/json.h"

namespace QTacitGame
{

    namespace Utils
    {

        namespace JsonHelper
        {
            using nlohmann::json;

            template <class T>
            T getAndCheckType(const json& js, const std::string& key, json::value_t type)
            {
                auto it = js.find(key);
                if(it == js.end())
                    throw std::runtime_error("invalid json object, unable to find " + key);
                if(it->type() != type)
                    throw std::runtime_error("invalid json object, the " + key + " field is not of the good type");
                return *it;
            }

            template <class T> T getAndCheckNumber(const json& js, const std::string& key)
            {
                auto it = js.find(key);
                if(it == js.end())
                    throw std::runtime_error("invalid json object, unable to find " + key);
                if(it->type() != json::value_t::number && it->type() != json::value_t::number_float)
                    throw std::runtime_error("invalid json object, the " + key + " field is not of the good type");
                return *it;
            }
	}

    } //Utils

} //QTacitGame
