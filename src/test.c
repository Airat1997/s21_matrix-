#include <check.h>

#include "s21_matrix.h"

void initialization(matrix_t *A) {
  int count = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = count++;
    }
  }
}

START_TEST(s21_create_matrix_1) {
  matrix_t A1 = {0};
  int rez1 = s21_create_matrix(0, 0, &A1);
  ck_assert_int_eq(rez1, 1);
  s21_remove_matrix(&A1);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t A2 = {0};
  int rez2 = s21_create_matrix(2, 0, &A2);
  ck_assert_int_eq(rez2, 1);
  s21_remove_matrix(&A2);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A3 = {0};
  int rez3 = s21_create_matrix(0, 2, &A3);
  ck_assert_int_eq(rez3, 1);
  s21_remove_matrix(&A3);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A4 = {0};
  int rez4 = s21_create_matrix(2, 2, &A4);
  ck_assert_int_eq(rez4, 0);
  s21_remove_matrix(&A4);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t A5 = {0};
  int rez5 = s21_create_matrix(-2, -2, &A5);
  ck_assert_int_eq(rez5, 1);
  s21_remove_matrix(&A5);
}
END_TEST

START_TEST(s21_eq_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &A);
  initialization(&A);
  initialization(&B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &A);
  initialization(&A);
  initialization(&B);
  B.matrix[0][0] = 42;
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &A);
  initialization(&A);
  initialization(&B);
  B.matrix[0][0] = 3.1111519;
  B.matrix[1][0] = 3.1151118;
  B.matrix[2][0] = 3.1121193;

  A.matrix[0][0] = 3.1111519;
  A.matrix[1][0] = 3.1151118;
  A.matrix[2][0] = 3.1121193;
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &A);
  initialization(&A);
  initialization(&B);
  B.matrix[0][0] = -3.1111519;
  B.matrix[1][0] = -0.1151118;
  B.matrix[2][0] = -3.11211935;
  // printf("%.8f\n", B.matrix[2][0]);
  A.matrix[0][0] = -3.1111519;
  A.matrix[1][0] = -0.1151118;
  A.matrix[2][0] = -3.11211935;
  // printf("%.8f\n", A.matrix[2][0]);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(2, 3, &A);
  initialization(&A);
  initialization(&B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(-1, 3, &A);
  s21_create_matrix(3, 3, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 3, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  matrix_t D = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &D);
  initialization(&A);
  initialization(&B);
  s21_sum_matrix(&A, &B, &C);
  D.matrix[0][0] = 2;
  D.matrix[1][0] = 8;
  D.matrix[2][0] = 14;
  ck_assert_int_eq(D.matrix[0][0], C.matrix[0][0]);
  ck_assert_int_eq(D.matrix[1][0], C.matrix[1][0]);
  ck_assert_int_eq(D.matrix[2][0], C.matrix[2][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&D);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_test) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(-1, 3, &A);
  s21_create_matrix(3, 3, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 3, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  matrix_t D = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &D);
  initialization(&A);
  initialization(&B);
  s21_sub_matrix(&A, &B, &C);
  D.matrix[0][0] = 0;
  D.matrix[1][0] = 0;
  D.matrix[2][0] = 0;
  ck_assert_int_eq(D.matrix[0][0], C.matrix[0][0]);
  ck_assert_int_eq(D.matrix[1][0], C.matrix[1][0]);
  ck_assert_int_eq(D.matrix[2][0], C.matrix[2][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&D);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_number_test) {
  matrix_t A = {0};
  matrix_t C = {0};
  double B = -0.1151118;
  s21_create_matrix(-1, 3, &A);
  ck_assert_int_eq(s21_mult_number(&A, B, &C), 1);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t A = {0};
  matrix_t C = {0};
  double B = -0.1151118;
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_mult_number(&A, B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t A = {0};
  matrix_t C = {0};
  matrix_t D = {0};
  double B = -1;
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = -1;
  D.matrix[1][0] = -4;
  D.matrix[2][0] = -7;
  s21_create_matrix(3, 3, &A);
  initialization(&A);
  s21_mult_number(&A, B, &C);
  ck_assert_int_eq(D.matrix[0][0], C.matrix[0][0]);
  ck_assert_int_eq(D.matrix[1][0], C.matrix[1][0]);
  ck_assert_int_eq(D.matrix[2][0], C.matrix[2][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(s21_mult_matrix_test) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(12, 32, &A);
  s21_create_matrix(32, 45, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(12, 32, &A);
  s21_create_matrix(3, 45, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(-1, 32, &A);
  s21_create_matrix(3, 45, &B);
  initialization(&A);
  initialization(&B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  matrix_t D = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &D);
  initialization(&A);
  initialization(&B);
  D.matrix[0][0] = 30;
  D.matrix[1][0] = 66;
  D.matrix[2][0] = 102;
  s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(D.matrix[0][0], C.matrix[0][0]);
  ck_assert_int_eq(D.matrix[1][0], C.matrix[1][0]);
  ck_assert_int_eq(D.matrix[2][0], C.matrix[2][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&D);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_transpose_test) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(5, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_transpose(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(-5, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_transpose(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &C);
  initialization(&A);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = 3;
  C.matrix[0][2] = 5;
  C.matrix[1][0] = 2;
  C.matrix[1][1] = 4;
  C.matrix[1][2] = 6;
  s21_transpose(&A, &B);
  ck_assert_int_eq(C.matrix[0][0], B.matrix[0][0]);
  ck_assert_int_eq(C.matrix[0][1], B.matrix[0][1]);
  ck_assert_int_eq(C.matrix[0][2], B.matrix[0][2]);
  ck_assert_int_eq(C.matrix[1][0], B.matrix[1][0]);
  ck_assert_int_eq(C.matrix[1][1], B.matrix[1][1]);
  ck_assert_int_eq(C.matrix[1][2], B.matrix[1][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_test) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(5, 5, &A);
  initialization(&A);
  ck_assert_int_eq(s21_calc_complements(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(s21_calc_complements_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(-1, 5, &A);
  initialization(&A);
  ck_assert_int_eq(s21_calc_complements(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(5, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_calc_complements(&A, &B), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  initialization(&A);
  ck_assert_int_eq(s21_calc_complements(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_calc_complements_test_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  C.matrix[0][0] = -1;
  C.matrix[0][1] = 38;
  C.matrix[0][2] = -27;
  C.matrix[1][0] = 1;
  C.matrix[1][1] = -41;
  C.matrix[1][2] = 29;
  C.matrix[2][0] = -1;
  C.matrix[2][1] = 34;
  C.matrix[2][2] = -24;
  s21_calc_complements(&A, &B);
  ck_assert_int_eq(C.matrix[0][0], B.matrix[0][0]);
  ck_assert_int_eq(C.matrix[0][1], B.matrix[0][1]);
  ck_assert_int_eq(C.matrix[0][2], B.matrix[0][2]);
  ck_assert_int_eq(C.matrix[1][0], B.matrix[1][0]);
  ck_assert_int_eq(C.matrix[1][1], B.matrix[1][1]);
  ck_assert_int_eq(C.matrix[1][2], B.matrix[1][2]);
  ck_assert_int_eq(C.matrix[2][0], B.matrix[2][0]);
  ck_assert_int_eq(C.matrix[2][1], B.matrix[2][1]);
  ck_assert_int_eq(C.matrix[2][2], B.matrix[2][2]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

START_TEST(s21_determinant_test) {
  matrix_t A = {0};
  double B = 0;
  s21_create_matrix(-1, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_determinant(&A, &B), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A = {0};
  double B = 0;
  s21_create_matrix(2, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_determinant(&A, &B), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A = {0};
  double B = 0;
  s21_create_matrix(3, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_determinant(&A, &B), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A = {0};
  double B = 0;
  s21_create_matrix(4, 4, &A);
  initialization(&A);
  s21_determinant(&A, &B);
  ck_assert_int_eq(B, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(-1, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  initialization(&A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &C);
  initialization(&A);
  C.matrix[0][0] = -2;
  C.matrix[0][1] = 1;
  C.matrix[1][0] = 1.5;
  C.matrix[1][1] = 0.5;
  s21_inverse_matrix(&A, &B);

  ck_assert_int_eq(C.matrix[0][0], B.matrix[0][0]);
  ck_assert_int_eq(C.matrix[0][1], B.matrix[0][1]);
  ck_assert_int_eq(C.matrix[1][0], B.matrix[1][0]);
  ck_assert_int_eq(C.matrix[1][1], B.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_matrix");
  TCase *tc1_1 = tcase_create("s21_matrix");
  SRunner *sr = srunner_create(s1);
  int nf = 0;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_create_matrix_1);
  tcase_add_test(tc1_1, s21_create_matrix_2);
  tcase_add_test(tc1_1, s21_create_matrix_3);
  tcase_add_test(tc1_1, s21_create_matrix_4);
  tcase_add_test(tc1_1, s21_create_matrix_5);
  tcase_add_test(tc1_1, s21_eq_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_2);
  tcase_add_test(tc1_1, s21_eq_matrix_4);
  tcase_add_test(tc1_1, s21_eq_matrix_5);
  tcase_add_test(tc1_1, s21_eq_matrix_6);
  tcase_add_test(tc1_1, s21_sum_matrix_test);
  tcase_add_test(tc1_1, s21_sum_matrix_test_2);
  tcase_add_test(tc1_1, s21_sum_matrix_test_3);
  tcase_add_test(tc1_1, s21_sum_matrix_test_4);
  tcase_add_test(tc1_1, s21_sub_matrix_test);
  tcase_add_test(tc1_1, s21_sub_matrix_test_2);
  tcase_add_test(tc1_1, s21_sub_matrix_test_3);
  tcase_add_test(tc1_1, s21_sub_matrix_test_4);
  tcase_add_test(tc1_1, s21_mult_number_test);
  tcase_add_test(tc1_1, s21_mult_number_test_2);
  tcase_add_test(tc1_1, s21_mult_number_test_3);
  tcase_add_test(tc1_1, s21_mult_matrix_test);
  tcase_add_test(tc1_1, s21_mult_matrix_test_2);
  tcase_add_test(tc1_1, s21_mult_matrix_test_3);
  tcase_add_test(tc1_1, s21_mult_matrix_test_4);
  tcase_add_test(tc1_1, s21_mult_matrix_test_5);
  tcase_add_test(tc1_1, s21_transpose_test);
  tcase_add_test(tc1_1, s21_transpose_test_2);
  tcase_add_test(tc1_1, s21_transpose_test_3);
  tcase_add_test(tc1_1, s21_calc_complements_test);
  tcase_add_test(tc1_1, s21_calc_complements_test_2);
  tcase_add_test(tc1_1, s21_calc_complements_test_3);
  tcase_add_test(tc1_1, s21_calc_complements_test_4);
  tcase_add_test(tc1_1, s21_calc_complements_test_5);
  tcase_add_test(tc1_1, s21_determinant_test);
  tcase_add_test(tc1_1, s21_determinant_test_2);
  tcase_add_test(tc1_1, s21_determinant_test_3);
  tcase_add_test(tc1_1, s21_determinant_test_4);
  tcase_add_test(tc1_1, s21_inverse_matrix_test);
  tcase_add_test(tc1_1, s21_inverse_matrix_test_2);
  tcase_add_test(tc1_1, s21_inverse_matrix_test_3);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
