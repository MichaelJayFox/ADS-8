// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(): first(nullptr), countOp(0) {}
int Train::getOpCount() {
    return countOp;
}
int Train::getLength() {
    Cage* CageWg = first;
    CageWg->light = 1;

    int rezult = 0;
    int countCageW = 1;
    while (CageWg) {
        CageWg = CageWg->next;
        if (CageWg->light == 0) {
            countCageW++;
            countOp++;
        }
        if (CageWg->light == 1) {
            CageWg -> light = 0;
            countOp++;
            for (int i = countCageW; i > 0; i--) {
                               CageWg = CageWg->prev;
                                countOp++;
                        }
                        if (CageWg->light == 0) {
                                return countCageW;
                        }
                        countCageW = 1;
        }
    }
    return -1;
}
void Train::addCage(bool light) {
  Cage* ptr = new Cage;
  ptr->light = light;
  ptr->next = nullptr;
  ptr->prev = nullptr;
  if (first == nullptr) {
    first = ptr;
  } else {
    if (first->next == nullptr) {
      first->next = ptr;
      first->prev = ptr;
      ptr->prev = first;
      ptr->next = first;
    } else {
      Cage* cg = first;
      while (cg->next != first) {
        cg = cg->next;
      }
      cg->next = ptr;
      ptr->prev = cg;
      ptr->next = first;
      first->prev  = ptr;
    }
  }
  countOp = 0;
}

