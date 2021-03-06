/*
Minetest
Copyright (C) 2017 Nore, Nathanaël Courant <nore@mesecons.net>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once

#warning ----TODO to deal with translation because of https://github.com/sba1/adtools/issues/92

#include <unordered_map>
#include <string>

class Translations;
extern Translations *g_translations;

class Translations
{
public:
	Translations() = default;

	~Translations();

	void loadTranslation(const std::string &data);
	void clear();
	const std::wstring &getTranslation(
			const std::wstring &textdomain, const std::wstring &s);

private:
#ifdef __amigaos4__
	std::unordered_map<std::string, std::string> m_translations;
#else
	std::unordered_map<std::wstring, std::wstring> m_translations;
#endif
};
