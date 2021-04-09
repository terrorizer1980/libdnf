/*
Copyright (C) 2018-2020 Red Hat, Inc.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef LIBDNF_CONF_VARS_HPP
#define LIBDNF_CONF_VARS_HPP

#include <map>
#include <string>
#include <vector>

namespace libdnf {

/// @class Vars
///
/// @brief Class for reading and substituting DNF vars (arch, releasever, etc.).
///
/// The class loads the variables from the environment as well as from a list
/// of directories.
struct Vars {
public:
    /// @brief Substitute DNF vars in the input text.
    ///
    /// @param text The text for substitution
    /// @return The substituted text
    std::string substitute(const std::string & text) const;

    const std::map<std::string, std::string> & get_values() const { return values; }

    /// @brief Set particular variable to a value
    ///
    /// @param name Name of the variable
    /// @param value Value to be stored in variable
    void set_value(const std::string & name, const std::string & value) { values[name] = value; }

    /// @brief Loads DNF vars from the environment and the passed directories.
    ///
    /// Environment variables are loaded first, then the directories are loaded
    /// in the order they are stored in the vector. Variables will overwrite
    /// any previous occurrence of a variable with the same name.
    ///
    /// @param installroot The path to the installroot
    /// @param directories The directories to load vars from
    void load(const std::string & installroot, const std::vector<std::string> & directories);

private:
    /// @brief Detects the system's arch, basearch and relesever.
    ///
    /// @param installroot The installroot directory
    void detect_vars(const std::string & installroot);

    /// @brief Loads DNF vars from a directory.
    ///
    /// Each file in the directory represents one variable. The filename stands
    /// for the name of the variable and the value is the first line of the
    /// file's contents.
    ///
    /// @param directory Path to a directory with DNF vars
    void load_from_dir(const std::string & directory);

    /// @brief Loads DNF vars from the environment.
    ///
    /// Reads environment variables that match "DNF[0-9]" and
    /// "DNF_VAR_[A-Za-z0-9_]+" patterns. The "DNF_VAR_" prefix is cut off.
    void load_from_env();

    std::map<std::string, std::string> values;
};

}  // namespace libdnf

#endif