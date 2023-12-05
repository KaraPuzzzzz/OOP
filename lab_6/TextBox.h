#pragma once

__interface TextBox
{
public:
	virtual void setText(std::string& text) /*= 0*/;
	virtual const std::string& getText() const /*= 0*/; 
	virtual void onValueChanged()/* = 0 */;
};
