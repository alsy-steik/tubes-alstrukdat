// #include "setmap.h"
// #include <stdio.h>

// int main() {

//     Map map;
//     MapCreateEmpty(&map);
//     printf("isEmpty (expected 1): %d\n", MapIsEmpty(map));
    
//     MapInsert(&map, "diddy", 12);
//     MapInsert(&map, "ijat", 13);
//     MapInsert(&map, "fakyumanig", 122);
//     printf("isEmpty (expected 0): %d\n", MapIsEmpty(map));

//     printf("contains (expected 1): %d\n", MapContains(map, "diddy"));
//     printf("contains (expected 0): %d\n", MapContains(map, "bjirlah"));

//     printf("getEl (expected 13): %d\n", MapGetEl(map, "ijat"));
//     MapDelete(&map, "ijat");
//     printf("getEl (expected -1): %d\n", MapGetEl(map, "ijat"));
//     printf("getEl (expected -1): %d\n", MapGetEl(map, "asas"));
    
//     return 0;
// }
