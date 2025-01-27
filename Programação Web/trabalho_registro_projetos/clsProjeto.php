<?php
require_once 'clsConexao.php';

class clsProjeto {
    private $conexao;

    public function __construct() {
        $this->conexao = clsConexao::getInstancia();
    }

    public function inserir($nome, $salario, $idEquipe) {
        $sqlProjeto = "INSERT INTO tb_projetos (nome, salario) VALUES (?, ?)";
        $parametrosProjeto = [$nome, $salario];
        $stmtProjeto = $this->conexao->executarConsulta($sqlProjeto, $parametrosProjeto);
    
        if ($stmtProjeto->affected_rows > 0) {
            $sqlConsultaId = "SELECT id_projeto FROM tb_projetos WHERE nome = ? AND salario = ? ORDER BY id_projeto DESC LIMIT 1";
            $parametrosConsultaId = [$nome, $salario];
            $stmtConsultaId = $this->conexao->executarConsulta($sqlConsultaId, $parametrosConsultaId);
    
            $resultado = $stmtConsultaId->get_result();
            $idProjeto = $resultado->fetch_assoc()['id_projeto'];
    
            $sqlAssociacao = "INSERT INTO tb_projetos_equipes (id_projeto, id_equipe) VALUES (?, ?)";
            $parametrosAssociacao = [$idProjeto, $idEquipe];
            $stmtAssociacao = $this->conexao->executarConsulta($sqlAssociacao, $parametrosAssociacao);
    
            return $stmtAssociacao->affected_rows > 0;
        }
    
        return false;
    }
    
    public function selecionarTodos() {
        $sql = "
            SELECT 
                p.id_projeto, 
                p.nome AS nome_projeto, 
                p.salario, 
                e.id_equipe, 
                e.nome AS nome_equipe 
            FROM 
                tb_projetos p
            LEFT JOIN 
                tb_projetos_equipes pe ON p.id_projeto = pe.id_projeto
            LEFT JOIN 
                tb_equipe e ON pe.id_equipe = e.id_equipe
        ";
    
        $stmt = $this->conexao->executarConsulta($sql);
        $resultado = $stmt->get_result();
        return $resultado->fetch_all(MYSQLI_ASSOC);
    }

    public function excluir($idProjeto) {
        $sql = "DELETE FROM tb_projetos WHERE id_projeto = ?";
        $parametros = [$idProjeto];
        $stmt = $this->conexao->executarConsulta($sql, $parametros);
        return $stmt->affected_rows > 0;
    }
}
?>