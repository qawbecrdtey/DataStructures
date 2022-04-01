add_library(list-datastructure src/list.c)
target_include_directories(list-datastructure PUBLIC include)

add_library(stack-datastructure src/stack.c)
target_include_directories(stack-datastructure PUBLIC include)

add_library(queue-datastructure src/queue.c)
target_include_directories(queue-datastructure PUBLIC include)