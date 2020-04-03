/*Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    }     
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character */

vector<string> ChangeInput(string str)
{
    vector<string> result;
    if (str.length() == 0) 
        return result;
 
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
 
    string indent = "";
    string curr = "";
    int i = 0, len = str.length();
     
    while (i < len)
    {
        curr.push_back(str[i]);
        switch(str[i])
        {
            case ',':
                result.push_back(curr);
                curr = indent;
                i++;
                break;
 
            case ':':
                i++;
                if (str[i] == '{' || str[i] == '[')
                {
                    result.push_back(curr);
                    curr = indent;
                }
                break;
 
            case '{':
            case '[':
 
                i++;
                result.push_back(curr);
                if (i < len && (str[i] != '}' || str[i] != ']'))
                {
                    indent.push_back('\t');
                }
                curr = indent;
                break;
 
            case '}':
            case ']':
                i++;
                if (i < len && str[i] == ',') break;
                result.push_back(curr);
                if (i < len && (str[i] == '}' || str[i] == ']'))
                {
                    if (!indent.empty()) indent.pop_back();
                }
                curr = indent;
                break;
 
            default : 
                i++;
                if (i < len && (str[i] == '}' || str[i] == ']'))
                {
                    result.push_back(curr);
                    if (!indent.empty()) indent.pop_back();
                    curr = indent;
                }
        }
    }
    return result;
}