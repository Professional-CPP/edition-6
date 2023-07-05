
class Card
{
public:
	enum class Number { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
	enum class Figure { Diamond, Heart, Spade, Club };

	Card() {}
	Card(Number number, Figure figure)
		: m_number { number }, m_figure { figure } {}
private:
	Number m_number{ Number::Ace };
	Figure m_figure{ Figure::Diamond };
};

//// The problem with the following representation for a deck of cards is that it
//// is impossible to guarantee certain invariants. For example, an initial deck of
//// cards has exactly 52 cards, all different from each other. With a simple array,
//// everyone can just manipulate the array of cards, adding duplicate cards, and so on.

//int main()
//{
//	Card deck[52];
//	// ...
//}



//// A better approach is to wrap a deck of cards in a class, which enforces any
//// invariants, and which can include additional functionality such as shuffling a deck.

import std;

class Deck
{
public:
	Deck() { /* Initialize a valid deck of cards... */ }
	
	// Retrieves the card with given index.
	// Throws std::out_of_range if index is an invalid index.
	const Card& getCard(std::size_t index) const { /* Validate index and return the card with given index... */ }

	// Shuffles the deck of cards.
	void shuffle() { /* Shuffle the deck... */ }

	// More member functions ...

private:
	std::vector<Card> m_deck;
};

int main()
{
	Deck deck;
	// ...
}