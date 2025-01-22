<?php
require_once 'clsConexao.php';

class clsFuncionario {
    private $conexao;

    public function __construct() {
        $this->conexao = clsConexao::getInstancia();
    }

    public function inserir($nome, $email, $idEquipe) {
        $sqlFuncionario = "INSERT INTO tb_funcionario (nome, email) VALUES (?, ?)";
        $parametrosFuncionario = [$nome, $email];
        $stmtFuncionario = $this->conexao->executarConsulta($sqlFuncionario, $parametrosFuncionario);
    
        if ($stmtFuncionario->affected_rows > 0) {
            $sqlConsultaId = "SELECT id_funcionario FROM tb_funcionario WHERE nome = ? AND email = ? ORDER BY id_funcionario DESC LIMIT 1";
            $parametrosConsultaId = [$nome, $email];
            $stmtConsultaId = $this->conexao->executarConsulta($sqlConsultaId, $parametrosConsultaId);
    
            $resultado = $stmtConsultaId->get_result();
            $idFuncionario = $resultado->fetch_assoc()['id_funcionario'];
    
            $sqlAssociacao = "INSERT INTO funcionarios_equipes (id_funcionario, id_equipe) VALUES (?, ?)";
            $parametrosAssociacao = [$idFuncionario, $idEquipe];
            $stmtAssociacao = $this->conexao->executarConsulta($sqlAssociacao, $parametrosAssociacao);
    
            return $stmtAssociacao->affected_rows > 0;
        }
    
        return false;
    }
    
    public function selecionarTodos() {
        $sql = "
            SELECT 
                f.id_funcionario, 
                f.nome AS nome_funcionario, 
                f.email, 
                e.id_equipe, 
                e.nome AS nome_equipe 
            FROM 
                tb_funcionario f
            LEFT JOIN 
                funcionarios_equipes fe ON f.id_funcionario = fe.id_funcionario
            LEFT JOIN 
                tb_equipe e ON fe.id_equipe = e.id_equipe
            ORDER BY 
                f.id_funcionario
        ";
    
        $stmt = $this->conexao->executarConsulta($sql);
        $resultado = $stmt->get_result();
        return $resultado->fetch_all(MYSQLI_ASSOC);
    }

    public function excluir($idFuncionario) {
        $sql = "DELETE FROM tb_funcionario WHERE id_funcionario = ?";
        $parametros = [$idFuncionario];
        $stmt = $this->conexao->executarConsulta($sql, $parametros);
        return $stmt->affected_rows > 0;
    }
}
?>