#pragma once
#include "./class_list.h"
#include "./multi_insert_tail.h"

template <typename To, typename From>
using ClassListMultiInsertHead = ClassListMultiInsertTail<From, To>;
