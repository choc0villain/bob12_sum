#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>

int main() {
    // 파일 경로 설정
    char file1_path[] = "thousand.bin";
    char file2_path[] = "five-hundred.bin";

    // 파일 포인터 초기화
    FILE *file1 = fopen(file1_path, "rb");
    FILE *file2 = fopen(file2_path, "rb");

    // 파일 열기에 실패한 경우 오류 출력 후 프로그램 종료
    if (file1 == NULL || file2 == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }
    
    uint32_t n1;
    uint32_t n2;
    
    // 파일에서 네트워크 바이트 숫자를 읽어와 합산
    if (fread(&n1, sizeof(uint32_t), 1, file1) != 1) {
        printf("첫 번째 파일에서 네트워크 바이트 숫자를 읽을 수 없습니다.\n");
        return 1;
    }

    if (fread(&n2, sizeof(uint32_t), 1, file2) != 1) {
        printf("두 번째 파일에서 네트워크 바이트 숫자를 읽을 수 없습니다.\n");
        return 1;
    }

    // 네트워크 바이트 순서를 호스트 바이트 순서로 변환 (네트워크 바이트 오더는 빅 엔디안)
    n1 = ntohl(n1);
    n2 = ntohl(n2);
    uint32_t sum = n1 + n2;
    
    // 결과 출력
     printf("%u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n", n1, n1, n2, n2, sum, sum);

    // 파일 닫기
    fclose(file1);
    fclose(file2);
}

