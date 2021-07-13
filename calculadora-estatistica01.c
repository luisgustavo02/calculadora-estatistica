#include<stdio.h>
#include<math.h>
#include<locale.h>
//BIBLIOTECAS ADICIONADAS

int main(){
	setlocale(LC_ALL, "Portuguese");
	//IDIOMA DEFINIDO COMO PORTUGUES
	
	int valores, i;
	float IncertezaInst;
	
	printf("\t\t\t\t\tPROGRAMA DE FÍSICA EXPERIMENTAL\n\n");
	printf("Digite quantos valores você deseja inserir:\n");
	scanf(" %i", &valores);
	fflush(stdin);
	printf("Digite a Incerteza Instrumental:\n");
	scanf(" %f", &IncertezaInst);
	fflush(stdin);
	printf("\n\n");
	
	float medidas[valores], soma=0, media;
	
	for(i=0;i<valores;i++){
		printf("Digite o %iº valor:\n", i+1);
		scanf(" %f", &medidas[i]);
		fflush(stdin);
		soma += medidas[i];
	}
	media = soma/valores;
	//CALCULO DA MEDIA E SOMA DAS MEDIDAS
	
	float DesvioPadrao, SomatorioDesvio=0, Variancia, DesvioPadraoMedia, Incerteza;
	
	for(i=0;i<valores;i++){
		SomatorioDesvio += pow((media - medidas[i]),2);
	}
	DesvioPadrao = sqrt(SomatorioDesvio/valores);
	Variancia = pow(DesvioPadrao, 2);
	DesvioPadraoMedia = DesvioPadrao/sqrt(valores);
	Incerteza = sqrt(pow(DesvioPadraoMedia,2) + pow(IncertezaInst, 2));
	//CALCULO DO DESVIO PADRAO, DESVIO PADRAO DA MEDIA, VARIANCA E INCERTEZA
	
	printf("\n\n");
	printf("Quantidade de valores digitados: %i\n", valores);
	printf("Somatório dos valores..........: %f\n", soma);
	printf("Média dos valores..............: %f\n", media);
	printf("Desvio padrão..................: %f\n", DesvioPadrao);
	printf("Variância......................: %f\n", Variancia);
	printf("Desvio padrão da média.........: %f\n", DesvioPadraoMedia);
	printf("Incerteza instrumental.........: %f\n", IncertezaInst);
	printf("Incerteza......................: %f\n", Incerteza);
	//APRESENTAÇÃO DE RESULTADOS
	
	system("Pause");
	
	return 0;
}
