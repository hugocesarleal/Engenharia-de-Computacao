package entidades;

public class Esporte {
	
	public String nome = "Ginástica Artística";
	
	public String link = "https://www.olimpiadato\r\n"
			+ "dodia.com.br/toquio2020/jogos-olimpicos/sk\r\n"
			+ "ate/";
	
	public int anoInclusao = 1896;
	
	public int medalhaOuro = 1;
	
	public int medalhaPrata = 1;
	
	public int medalhaBronze = 0;
	
	public void diferenca() {
		System.out.println("As diferenças entre as medalhas no Brasil e Estados Unidos nas"
				+ "Olimpíadas de Tóqui 2020 são:");
		
		System.out.println("Ouro: "+ (2-medalhaOuro));
		
		System.out.println("Prata: "+ (2-medalhaPrata));
		
		System.out.println("Bronze: "+ (2-medalhaBronze));
	}
}
