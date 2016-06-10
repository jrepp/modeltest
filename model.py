
alltypes = []

class GameType(object):
  def __init__(self):
    global alltypes
    alltypes.append(self)

class Resource(GameType):
  def __init__(self, name, cost, requires=[]):
    GameType.__init__(self)
    self.name = name
    self.cost = cost
    self.requires = requires

class BuildReq(GameType):
  def __init__(self, requiredType, count):
    GameType.__init__(self)
    self.requiredType = requiredType
    self.count = count

# Define game types
Resource('Sugar', 10, [])
Resource('Butter', 30, [])
Resource('Flour', 20, [])
Resource('Gold', 1, [])
Resource('Cookie', 100, [
  BuildReq('Sugar', 1),
  BuildReq('Butter', 1),
  BuildReq('Flour', 2)])

def generate_build_reqs_list(t):
  reqs = []
  for req in t.requires:
    reqs.append("{{ &{0}::s_singleton, {1} }}".format(req.requiredType, req.count))
  return ','.join(reqs)

def generate_cpp_class(t):

  print """
class %(type_name)s : public GameType {
public:
    static %(type_name)s s_singleton;

    %(type_name)s() {}
    ~%(type_name)s() {}
    
    const char* GetTypeName() const {{
        return "%(type_name)s";
    }    
    int GetTypeId() const {
        return %(type_id)s;
    }
    int GetCost() const {
        return  %(cost)s;
    }
    void GetBuildReqs(std::vector<std::pair<GameType*,int>>& buildReqs) const {
        static std::vector<std::pair<GameType*,int>> s_buildReqs = {
            %(build_reqs_list)s
        };
        buildReqs = s_buildReqs;
    }
};
  """ % {
    'type_name': t.name,
    'type_id': t.__hash__(),
    'cost': t.cost,
    'build_reqs_list': generate_build_reqs_list(t),
  }

def generate():
  for t in alltypes:
    if issubclass(type(t), Resource):
      generate_cpp_class(t)
    
if __name__ == '__main__':
    generate()

