#include<stdio.h>

int main(){
	int n;
	int arr[100];
	int choice;
	do{
		printf("\n Menu \n");
		printf("1. Nhap so phan tu can nhap va gia tri tung phan tu \n");
		printf("2. In ra gia tri cac phan tu dang quan ly \n");
		printf("3. In ra gia tri lon nhat cua mang \n");
		printf("4. In ra cac phan tu la so nguyen to trong mang \n");
		printf("5. Them 1 phan tu vao mang \n");
		printf("6. Xoa 1 phan tu trong mang \n");
		printf("7. Su dung Selection Sort de sap xep mang theo thu tu tang dan \n");
		printf("8. Su dung Linear Search de tim kiem va in ra vi tri index cua phan tu \n");
		printf("9. Thoat \n");
		printf("Nhap lua chon : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : {
				printf("Nhap vao do dai mang : ");
				scanf("%d",&n);
				if(n <= 0){
					printf("Nhap lai do dai mang > 0");
					break;
				}
				for(int i = 0 ; i < n ; i++){
					printf("Nhap vao phan tu thu %d : ",i+1);
					scanf("%d",&arr[i]);
				}
				printf("Da nhap xong mang \n");
				break;
			} 
			case 2 : {
				if(n <= 0){
					printf("Mang chua duoc tao \n");
					break;
				}else{
					printf("Mang dang quan ly la : ");
					for(int i = 0 ; i < n ; i++){
						printf("%d \t",arr[i]);
					}	
				};
				break;
			}
			case 3 : {
				if(n <= 0){
					printf("Mang chua duoc tao \n");
					break;
				}else{
					int max = arr[0];
					for(int i = 0 ; i < n ; i++){
						if(max < arr[i]){
							max = arr[i];
						}
					}
					printf("Gia tri lon nhat cua mang la : %d",max);
				};
				break;
			}
			case 4 : {
				if(n <= 0){
					printf("Mang chua duoc tao \n");
					break;
				}else{
					int found = 0;
					printf("Cac phan tu la so nguyen to trong mang la : ");
					for(int i = 0 ; i < n ; i++){
						int number = arr[i];
						int isPrime = 1;
						if(number < 2){
							isPrime = 0;
						}else{
							for(int i = 2 ; i*i <= number ; i++){
								if(number % i == 0){
									isPrime = 0;
									break;
								}
							}
						}
						if(isPrime){
							printf("%d \t",number);
							found = 1;
						}
					}
					if(!found){
						printf("Khong co so nguyen trong mang \n");
					}
				}
				break;
			}
			case 5 :{
				int value , addIndex;
				printf("Nhap vao gia tri muon them vao : ");
				scanf("%d",&value);
				printf("Nhap vi tri muon them vao : ");
				scanf("%d",&addIndex);
				if(0> addIndex || addIndex > n){
					printf("Vi tri them vao khong hop le \n");
					break;
				}
				for(int i = n ; i > addIndex ; i--){
					arr[i] = arr[i-1];
				}
				arr[addIndex] = value;
				n++;
				printf("Mang sau khi them : \n");
				for(int i = 0 ; i < n ; i++){
					printf("%d \t",arr[i]);
				}
				break;
			}
			case 6 :{
				int deleteIndex;
				printf("Nhap vi tri muon xoa : ");
				scanf("%d",&deleteIndex);
				if(0 > deleteIndex || deleteIndex > n){
					printf("Vi tri xoa khong hop le \n");
					break;
				}
				for(int i = deleteIndex ; i < n - 1 ; i++){
					arr[i] = arr[i+1];
				}
				n--;
				printf("Mang sau khi xoa : \n");
				for(int i = 0 ; i < n ; i++){
					printf("%d \t",arr[i]);
				}
				break;
			}
			case 7 :{
				for(int i = 0 ; i < n - 1 ; i++){
					int minIndex = i;
					for(int j = i + 1 ; j < n ; j++){
						if(arr[j] < arr[minIndex]){
							minIndex = j;
						}
					}
					int temp = arr[minIndex];
					arr[minIndex] = arr[i];
					arr[i] = temp;
				}
				printf("Mang sau khi sap xep la : ");
				for(int i = 0 ; i < n ; i++){
					printf("%d \t",arr[i]);
				}
				break;
			}
			case 8 :{
				int findValue;
				int hasFound = 0;
				printf("Nhap gia tri muon tim : ");
				scanf("%d",&findValue);
				for(int i = 0 ; i < n ; i++){
					if(arr[i] == findValue){
						printf("Gia tri can tim o vi tri %d \n" , i+1);
						hasFound = 1;
					}
				}
				if(!hasFound){
					printf("Gia tri can tim khong co trong mang");
				}
				break;
			}
			case 9 :{
				printf("Thoat chuong trinh \n");
				break;
			}
			default :{
				printf("Vui long nhap lai tu 1 - 9\n");
				break;
			}
		}
	}while(choice!=9);
	return 0;
}
