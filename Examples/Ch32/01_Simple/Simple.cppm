export module simple;

// A simple class that illustrates class definition syntax.
export class Simple
{
public:
	Simple();                              // Constructor
	virtual ~Simple() = default;           // Defaulted virtual destructor

	// Disallow copy construction and copy assignment.
	Simple(const Simple& src) = delete;
	Simple& operator=(const Simple& rhs) = delete;

	// Explicitly default move constructor and move assignment operator.
	Simple(Simple&& src) = default;
	Simple& operator=(Simple&& rhs) = default;

	virtual void publicMemberFunction();   // Public member function
	int m_publicInteger;                   // Public data member

protected:
	virtual void protectedMemberFunction();// Protected member function
	int m_protectedInteger{ 41 };          // Protected data member

private:
	virtual void privateMemberFunction();  // Private member function
	int m_privateInteger{ 42 };            // Private data member
	static constexpr int Constant{ 2 };    // Private constant
	static inline int ms_staticInt{ 3 };   // Private static data member
};
