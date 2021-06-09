#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
  void Utilization(const float utilization);
  // TODO: Declare any necessary private members
 private:
    float utilization_;
};

#endif