/*


Problem Name: 1166. Design File System
Problem Link: https://leetcode.com/problems/design-file-system/?envType=problem-list-v2&envId=design


create
get


path -> value


create:     O(n)
    - if already exist:
        - return false
    - get the parent => O(n) (n: string length)
    - if parent does NOT exist:
        - return false
    - insert in hashmap => O(1)

getParent:
    - scan the string from end and check where you find the slash
    - NOTE: handle case where there is no parent "/example"

    There is a simpler way in CPP (using inbuilt functions) to find the last index of '/' 
    => READ: https://gist.github.com/vedantbothikar/2a6cd7c732b9e51bdb1f203abf5c2237


get:    O(1)
    - return if exists in mp else -1


*/
class FileSystem {

    unordered_map<string, int> paths;

public:
    FileSystem() {
        
    }

    string getParentPath(string path) {

        int n = path.size();
        int index = n-1;

        // NOTE: index wont go below 0 because there would always be a slash
        // according to constraints of this problem
        while(index >= 0 && path[index] != '/') {
            index--;
        }

        // get the substring parent path
        // NOTE: we are using index as the end pointer and not index+1
        // this is because our parent path will be
        // For example: /path1/path2
        // And NOT /path1/path2/
        // NOTE the slash at the end. That end slash is the index
        // And substr method excludes the end pointer
        string parent = path.substr(0, index);  

        return parent;
    }

    
    bool createPath(string path, int value) {
        
        // path already exists
        if(paths.find(path) != paths.end()) return false;

        // get parent path
        string parent = getParentPath(path);

        // case: no parent (parent == "")
        // this means create it anyway
        if(parent == "") {
            paths[path] = value;
            return true;
        }

        // if parent does NOT exist 
        if(paths.find(parent) == paths.end()) return false;

        // create the path
        paths[path] = value;

        return true;
    }
    
    int get(string path) {
        
        // path does not exist
        if(paths.find(path) == paths.end()) return -1;

        return paths[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */