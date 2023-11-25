import std;

using namespace std;

class Book
{
public:
	virtual ~Book() = default;
	virtual string getDescription() const { return "Book"; }
	virtual int getHeight() const { return 120; }
};

class Paperback : public Book
{
public:
	string getDescription() const override {
		return "Paperback " + Book::getDescription();
	}
};

class Romance : public Paperback
{
public:
	string getDescription() const override {
		return "Romance " + Paperback::getDescription();
	}
	int getHeight() const override { return Paperback::getHeight() / 2; }
};

class Technical : public Book
{
public:
	string getDescription() const override {
		return "Technical " + Book::getDescription();
	}
};

int main()
{
	Romance novel;
	Book book;
	println("{}", novel.getDescription()); // Outputs "Romance Paperback Book"
	println("{}", book.getDescription());  // Outputs "Book"
	println("{}", novel.getHeight());      // Outputs "60"
	println("{}", book.getHeight());       // Outputs "120"

}
