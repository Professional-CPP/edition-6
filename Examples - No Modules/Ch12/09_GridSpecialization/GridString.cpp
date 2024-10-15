#pragma once

#include "GridString.h"

Grid<const char*>::Grid(std::size_t width, std::size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width * m_height);
}

void Grid<const char*>::verifyCoordinate(std::size_t x, std::size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range { std::format("x ({}) must be less than width ({}).", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range { std::format("y ({}) must be less than height ({}).", y, m_height) };
	}
}

const std::optional<std::string>& Grid<const char*>::at(std::size_t x, std::size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x + y * m_width];
}

std::optional<std::string>& Grid<const char*>::at(std::size_t x, std::size_t y)
{
	return const_cast<std::optional<std::string>&>(std::as_const(*this).at(x, y));
}
