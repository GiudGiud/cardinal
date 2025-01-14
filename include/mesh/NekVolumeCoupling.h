#pragma once

#include "CardinalUtils.h"

class NekVolumeCoupling
{
public:
  /**
   * nekRS process owning the global element in the data transfer mesh
   * @param[in] elem_id element ID
   * @return nekRS process ID
   */
  int processor_id(const int elem_id) const { return process[elem_id]; }

  // process-local element IDS (for all elements)
  std::vector<int> element;

  // process owning each element (for all elements)
  std::vector<int> process;

  // sideset IDs corresponding to the faces of each element (for all elements)
  std::vector<int> boundary;

  // number of elements owned by each process
  std::vector<int> counts;

  // number of faces on a boundary of interest for each element
  std::vector<int> n_faces_on_boundary;

  // number of coupling elements owned by this process
  int n_elems = 0;

  // total number of coupling elements
  int total_n_elems = 0;
};
