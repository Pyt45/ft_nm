#include "nm.h"


t_pair map_region(int fd) {
    struct stat st;
    t_pair pair;

    pair.ptr = MAP_FAILED;
    pair.size = 0;
    int ret = fstat(fd, &st);

    if (ret < 0)
        return pair;
    pair.size = st.st_size;
    pair.ptr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    return pair;
}