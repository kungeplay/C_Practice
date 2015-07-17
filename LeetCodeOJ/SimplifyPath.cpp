// Simplify Path
// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

// Corner Cases:
//     Did you consider the case where path = "/../"?
//     In this case, you should return "/".
//     Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//     In this case, you should ignore redundant slashes and return "/home/foo".

#include <iostream>
#include <vector>
using namespace std;
//试了很长时间，总算对了，忽视了Unix下文件夹名字可以包含这样的"..."或者"...123"
class Solution {
public:
    string simplifyPath(string path) {
 
    		vector<string> path_v;
    		string temp_path="";
    		string simp_path;
    		size_t i=0;
    		int dot_num=0;
    		bool dot_all=true;
    		if(path[path.size()-1]!='/')//统一路径，使最后一个字符都为"/"
    			path.push_back('/');
    		while(i<path.size())
    		{
    			switch(path[i])
    			{
    				case '.':
    					++dot_num;
    					temp_path.push_back(path[i]);
					break;
				case '/':

					if(dot_num==2&&dot_all)
					{
						if(path_v.size()>0)
							path_v.pop_back();
					}
					else if(temp_path.size()>1&&(dot_num!=1||!dot_all))
						path_v.push_back(temp_path);

					dot_all=true;
					dot_num=0;
					temp_path="/";
					break;
				default:
					temp_path.push_back(path[i]);
					dot_all=false;
					break;

    			}
    			++i;	
    		}

    		for(size_t j=0;j<path_v.size();++j)
    		{
    			simp_path+=path_v[j];
    		}
    		if(simp_path.size()==0)
    			return "/";
    		else
	    		return simp_path;
    }
};
int main(int argc, char const *argv[])
{
	// string s="/home/foo/.ssh1/../.ssh2/authorized_keys/";
	string s="/home/";
	Solution so;
	cout<<so.simplifyPath(s)<<endl;
	return 0;
}