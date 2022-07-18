#include <iostream>
#include <vector>

std::vector<std::vector<int>> inputMatrix(int row, int column){
    std::vector<std::vector<int>> matrix(row, std::vector<int>(column, 0));
    for(int i = 0; i < row; i++){
        std::cout << "Введите значения " << i + 1 << "-ой строки" << std::endl;
        for(int j = 0; j < column; j++){
            std::cin >> matrix[i][j];
        };
    };
    return matrix;
};

void printMatrix(std::vector<std::vector<int>>& matrix, int row, int column){
    for(int i = 0; i < row; i++){
        std::cout << "[ ";
        for(int j = 0; j < column; j++){
            std::cout << matrix[i][j] << " ";
        };
        std::cout << "]" << std::endl;
    };
};

std::vector<std::vector<int>> addMatrix(std::vector<std::vector<int>>& first, std::vector<std::vector<int>>& second){
    int row = first.size(), column = first[0].size();
    std::vector<std::vector<int>> matrix(row, std::vector<int>(column, 0));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            matrix[i][j] = first[i][j] + second[i][j];
        };
    };
    return matrix;
};

std::vector<std::vector<int>> subMatrix(std::vector<std::vector<int>>& first, std::vector<std::vector<int>>& second){
    int row = first.size(), column = first[0].size();
    std::vector<std::vector<int>> matrix(row, std::vector<int>(column, 0));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            matrix[i][j] = first[i][j] - second[i][j];
        };
    };
    return matrix;
};

bool checkMult(std::vector<std::vector<int>>& first, std::vector<std::vector<int>>& second){
    if (first[0].size() == second.size()){
        return true;
    } else {
        return false;
    };
};

std::vector<std::vector<int>> multMatrix(std::vector<std::vector<int>>& first, std::vector<std::vector<int>>& second){
    if(checkMult(first, second)){
        int row = first.size(), column = second[0].size();
        std::vector<std::vector<int>> res(row, std::vector<int>(column, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                for(int k = 0; k < first[0].size(); k++){
                    res[i][j] += first[i][k] * second[k][j];
                };
            };
        };
        return res;
    } else {
        std::cout << "Нельзя перемножить матрицы" << std::endl;
    };
};

int main(){
    int n, m;
    std::cout << "Введите количество строк" << std::endl;
    std::cin >> n;
    std::cout << "Введите количество столбцов" << std::endl;
    std::cin >> m;
    std::vector<std::vector<int>> matrix1 = inputMatrix(n, m);
    std::cout << std::endl;
    printMatrix(matrix1, n, m);
    std::vector<std::vector<int>> matrix2 = inputMatrix(n, m);
    std::cout << std::endl;
    printMatrix(matrix2, n, m);
    std::cout << std::endl;
    std::vector<std::vector<int>> addmatrix = addMatrix(matrix1, matrix2);
    printMatrix(addmatrix, n, m);
    std::cout << std::endl;
    std::vector<std::vector<int>> submatrix = subMatrix(matrix1, matrix2);
    printMatrix(submatrix, n, m);
    std::cout << std::endl;
    std::vector<std::vector<int>> multmatrix = multMatrix(matrix1, matrix2);
    printMatrix(multmatrix, n, m);
    return 0;
};
