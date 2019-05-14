#ifndef CARDINAL_NEKPROBLEM_H
#define CARDINAL_NEKPROBLEM_H

#include "ExternalProblem.h"

#include <memory>

class NekProblem;

template<>
InputParameters validParams<NekProblem>();

class NekProblem : public ExternalProblem
{
public:
  NekProblem(const InputParameters & params);
  ~NekProblem(){}

  virtual void externalSolve() override;
  virtual void syncSolutions(ExternalProblem::Direction direction) override;

  virtual bool converged() override { return true; }

  virtual void addExternalVariables() override;

protected:
  std::unique_ptr<NumericVector<Number>> _serialized_solution;

  unsigned int _temp_var;
  unsigned int _avg_flux_var;
};

#endif //CARDINAL_NEKPROBLEM_H
