#include <stdio.h>

class ScriptPython {
public:
    bool useScriptPython() {
        FILE* pipe = _popen("python D:\\PhotoInExcel\\useExelScript.py", "r");

        if (!pipe) {
            std::cerr << "Error: Couldn't open pipe to Python script!" << std::endl;
            return 1;
        }

        _pclose(pipe);
        return 0;
    }
};