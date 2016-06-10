

class GameType {
  public:
    GameType() {}
    ~GameType() {}

    virtual int GetTypeName() const = 0;
    virtual int GetTypeId() const = 0;
    virtual int GetCost() const = 0;
};

#include "models.h"

void Sell(GameType& gt)
{
  printf("Sold %s for %d\n", gt.GetTypeName(), gt.GetCost());
  if (gt.IsContraband())
    printf("Got arrested\n");
}

int main() {

  Sell(Cookie());
  return 0;
}
