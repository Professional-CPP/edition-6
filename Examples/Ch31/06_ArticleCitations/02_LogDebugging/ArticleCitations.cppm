export module article_citations;

import std;

export class ArticleCitations
{
public:
	ArticleCitations(std::string_view filename);
	virtual ~ArticleCitations();
	ArticleCitations(const ArticleCitations& src);
	ArticleCitations& operator=(const ArticleCitations& rhs);

	const std::string& getArticle() const;
	int getNumCitations() const;
	const std::string& getCitation(int i) const;

private:
	void readFile(std::string_view filename);
	void copy(const ArticleCitations& src);

	std::string m_article;
	std::string* m_citations;
	int m_numCitations;
};
