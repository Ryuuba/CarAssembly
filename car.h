class AssemblyLine;

class Car {
private:
  unsigned bodywork, paint, mechanical_parts, electronics, decoration;
public:
  friend class AssemblyLine;
  Car() {
    bodywork = 0;
    paint = 0;
    mechanical_parts = 0;
    electronics = 0;
    decoration = 0;
  }
};