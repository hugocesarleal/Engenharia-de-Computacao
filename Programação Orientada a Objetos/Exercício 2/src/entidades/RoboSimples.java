package entidades;

public class RoboSimples {

	private String nome;
	private String direcao;
	private int cordX;
	private int cordY;
	
	public RoboSimples(String nome,int cordX, int cordY, String direcao) {
		this.nome = nome;
		this.cordX = cordX;
		this.cordY = cordY;
		this.direcao = direcao;
	}
	
	public RoboSimples(String nome) {
		this.nome = nome;
		cordX = 0;
		cordY = 0;
		direcao = "Norte";
	}
	
	public RoboSimples() {
		nome = "";
		cordX = 0;
		cordY = 0;
		direcao = "Norte";
	}
	
	public void moveUm() {
		if (direcao == "Norte") {
			cordY += 1;
		}
		if (direcao == "Sul") {
			cordY -= 1;
		}
		if (direcao == "Leste") {
			cordX += 1;
		}
		if (direcao == "Oeste") {
			cordX -= 1;
		}
	}
	
	public void moveN(int n) {
		if (direcao == "Norte") {
			cordY += n;
		}
		if (direcao == "Sul") {
			cordY -= n;
		}
		if (direcao == "Leste") {
			cordX += n;
		}
		if (direcao == "Oeste") {
			cordX -= n;
		}
	}
	
	public void mudarDirecao(String direcao) {
		this.direcao = direcao;
	}
	
	public void mostrar() {
		String posicao = "Nome do robô:"+nome+"\n";
		posicao = posicao + "Posição do robô:("+cordX+","+cordY+")\n";
		posicao = posicao +"Direção de robô: "+direcao;
		
		System.out.println(posicao);
		}
}
