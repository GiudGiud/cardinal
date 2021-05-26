[Mesh]
  type = FileMesh
  file = ../../../neutronics/meshes/pincell.e
[]

[Problem]
  type = OpenMCCellAverageProblem
  power = 500.0
  solid_blocks = '1 3'
  fluid_blocks = '2'
  tally_blocks = '1'
  verbose = true
  tally_filter = cell_instance
  solid_cell_level = 1
  fluid_cell_level = 1
[]

[Executioner]
  type = Transient
[]

[Outputs]
  exodus = true
[]
