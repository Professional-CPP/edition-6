export module game_board;

import grid;
import std;

export
template <typename T>
class GameBoard : public Grid<T>
{
public:
	// Inherit constructors from Grid<T>.
	using Grid<T>::Grid;

	void move(std::size_t xSrc, std::size_t ySrc, std::size_t xDest, std::size_t yDest);
};

template <typename T>
void GameBoard<T>::move(std::size_t xSrc, std::size_t ySrc, std::size_t xDest, std::size_t yDest)
{
	Grid<T>::at(xDest, yDest) = std::move(Grid<T>::at(xSrc, ySrc));
	Grid<T>::at(xSrc, ySrc).reset(); // Reset source cell
	// Or:
	// this->at(xDest, yDest) = std::move(this->at(xSrc, ySrc));
	// this->at(xSrc, ySrc).reset();
}
