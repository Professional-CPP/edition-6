class XrayController                                           //// xrayController: Class names start with an uppercase letter.
{
public:
	// Gets the active X-ray current in µA.
	double getCurrent() const;

	// Sets the current of the X-rays to the given current in µA.
	void setCurrent(double currentInMicroAmp);                 //// setIt(): too generic name.
	                                                           //// Val: parameters start with a lowercase letter.
	                                                           ////      and should have a meaningful name

	// Sets the current to 0 µA.
	void setZeroCurrent();                                     //// 0Current(): identifiers are not allowed to start with a digit.

	// Gets the X-ray source type.
	const std::string& getSourceType() const;

	// Sets the X-ray source type.
	void setSourceType(std::string_view type);                 //// _Type: identifiers should not start with an underscore followed by a capital.

private:
	double m_current; // The X-ray current in µA.              //// d: too short and meaningless. Data members start with m_
	std::string m_sourceType; // The type of the X-ray source. //// m_src__type: double underscores and abbreviations are not allowed. 
};
