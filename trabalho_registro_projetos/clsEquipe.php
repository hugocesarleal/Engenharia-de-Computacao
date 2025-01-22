<?php
require_once 'clsConexao.php';

class clsEquipe {
    private $conexao;

    public function __construct() {
        $this->conexao = clsConexao::getInstancia();
    }

    public function inserir($nome) {
        $sql = "INSERT INTO tb_equipe (nome) VALUES (?)";
        $parametros = [$nome];
        $stmt = $this->conexao->executarConsulta($sql, $parametros);
        return $stmt->affected_rows > 0;
    }

    public function selecionarTodos() {
        $sql = "SELECT * FROM tb_equipe ORDER BY nome";
        $stmt = $this->conexao->executarConsulta($sql);
        $resultado = $stmt->get_result();
        return $resultado->fetch_all(MYSQLI_ASSOC);
    }

    public function excluir($idEquipe) {
        $sql = "DELETE FROM tb_equipe WHERE id_equipe = ?";
        $parametros = [$idEquipe];
        $stmt = $this->conexao->executarConsulta($sql, $parametros);
        return $stmt->affected_rows > 0;
    }
}
?>