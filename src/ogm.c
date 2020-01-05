/*
* @Author: AnthonyKenny98
* @Date:   2019-12-08 08:10:44
* @Last Modified by:   AnthonyKenny98
* @Last Modified time: 2020-01-05 17:03:42
*/

#include "ogm.h"

void initObstacles(space_t *space) {
    // Open File
    FILE *f = fopen("cache/ogm.csv","r");
    
    // Fill out OGM based on csv
    int temp;
    for(int i=XDIM/RESOLUTION-1;i>=0;i--){
        for(int j=0;j<YDIM/RESOLUTION;j++){
            fscanf(f, "%i,", &temp);
            // Reverse i and j because we read csv opposite way
            // to the way the grid is set up (cartesian)
            space->ogm[j][i] = (bool) temp;
        }
        fscanf(f,"\n");  
    }
}

// Returns true if point collides with obstacle
bool pointCollision(point_t node, space_t *space) {
    return space->ogm[grid_lookup(node.x)][grid_lookup(node.y)];
}

int grid_lookup(double val) {
    return (int) val/RESOLUTION;
}