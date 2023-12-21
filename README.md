# OctoShaker
The repository for OctoShaker contains the files for robotic control and the CAD file.

The CAD file contains the final version of the OctoShaker, and the assembly instruction can be found by accessing the article supplementary material referenced below. For 3D printing, beaware of using the exact parameters and allow tolerances depending on individual printers. It is best to print few variations at once to select the best parameters for the specific printer.

Robotic control files contain the two main folder: "Sequencing" and "Motions." The "Sequencing" folder contains the template for piecing together different motions for desired workflow. 3D Vortex Motion and SeeSaw Motion has been added as an example can the same can be done to insert other pre-defined or user-defined motions. The "Motions" folder contains the pre-programmed motions, in which Axial1 refers to SeeSaw motion and Axial2-3 refers to 3D Vortex motion. Within the "Motions" folder contains categorized motions, where "Shake" and "Vertical" adds additional features to the "Normal" motions. The "Test" folder contains additional code used for rpm calculation.

The article can be found at "OctoShaker: A versatile robotic biomechanical agitator for cellular and organoid research" at Review of Scientific Instruments journal.

Please cite the article if used the provided code, thank you!
Yan Huang, Soojung Lee, Wenhao Liu, Shuichi Takayama, Shu Jia; OctoShaker: A versatile robotic biomechanical agitator for cellular and organoid research. Rev. Sci. Instrum. 1 December 2023; 94 (12): 124104. https://doi.org/10.1063/5.0174526

