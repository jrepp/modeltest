
class Sugar : public GameType {
public:
    static Sugar s_singleton;

    Sugar() {}
    ~Sugar() {}
    
    const char* GetTypeName() const {
        return "Sugar";
    }    
    int GetTypeId() const {
        return 2890889;
    }
    int GetCost() const {
        return  10;
    }
    void GetBuildReqs(std::vector<std::pair<GameType*,int>>& buildReqs) const {
        static std::vector<std::pair<GameType*,int>> s_buildReqs = {
            
        };
        buildReqs = s_buildReqs;
    }
};
  

class Butter : public GameType {
public:
    static Butter s_singleton;

    Butter() {}
    ~Butter() {}
    
    const char* GetTypeName() const {
        return "Butter";
    }    
    int GetTypeId() const {
        return 2890901;
    }
    int GetCost() const {
        return  30;
    }
    void GetBuildReqs(std::vector<std::pair<GameType*,int>>& buildReqs) const {
        static std::vector<std::pair<GameType*,int>> s_buildReqs = {
            
        };
        buildReqs = s_buildReqs;
    }
};
  

class Flour : public GameType {
public:
    static Flour s_singleton;

    Flour() {}
    ~Flour() {}
    
    const char* GetTypeName() const {
        return "Flour";
    }    
    int GetTypeId() const {
        return 2890903;
    }
    int GetCost() const {
        return  20;
    }
    void GetBuildReqs(std::vector<std::pair<GameType*,int>>& buildReqs) const {
        static std::vector<std::pair<GameType*,int>> s_buildReqs = {
            
        };
        buildReqs = s_buildReqs;
    }
};
  

class Gold : public GameType {
public:
    static Gold s_singleton;

    Gold() {}
    ~Gold() {}
    
    const char* GetTypeName() const {
        return "Gold";
    }    
    int GetTypeId() const {
        return 2890905;
    }
    int GetCost() const {
        return  1;
    }
    void GetBuildReqs(std::vector<std::pair<GameType*,int>>& buildReqs) const {
        static std::vector<std::pair<GameType*,int>> s_buildReqs = {
            
        };
        buildReqs = s_buildReqs;
    }
};
  

class Cookie : public GameType {
public:
    static Cookie s_singleton;

    Cookie() {}
    ~Cookie() {}
    
    const char* GetTypeName() const {
        return "Cookie";
    }    
    int GetTypeId() const {
        return 2890913;
    }
    int GetCost() const {
        return  100;
    }
    void GetBuildReqs(std::vector<std::pair<GameType*,int>>& buildReqs) const {
        static std::vector<std::pair<GameType*,int>> s_buildReqs = {
            { &Sugar::s_singleton, 1 },{ &Butter::s_singleton, 1 },{ &Flour::s_singleton, 2 }
        };
        buildReqs = s_buildReqs;
    }
};
  
