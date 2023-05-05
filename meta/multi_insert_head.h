#pragma once
#include "meta/class_list.h"
#include "meta/multi_insert_tail.h"

template <typename To, typename From>
using ClassListMultiInsertHead = ClassListMultiInsertTail<From, To>;
