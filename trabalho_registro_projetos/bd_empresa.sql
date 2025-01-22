-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 17/11/2024 às 18:23
-- Versão do servidor: 10.4.32-MariaDB
-- Versão do PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `bd_empresa`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `funcionarios_equipes`
--

CREATE TABLE `funcionarios_equipes` (
  `id_funcionario` int(11) NOT NULL,
  `id_equipe` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `funcionarios_equipes`
--

INSERT INTO `funcionarios_equipes` (`id_funcionario`, `id_equipe`) VALUES
(29, 10),
(30, 11),
(31, 12),
(36, 13),
(37, 14),
(38, 11),
(39, 10),
(40, 12);

-- --------------------------------------------------------

--
-- Estrutura para tabela `tb_equipe`
--

CREATE TABLE `tb_equipe` (
  `id_equipe` int(11) NOT NULL,
  `nome` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `tb_equipe`
--

INSERT INTO `tb_equipe` (`id_equipe`, `nome`) VALUES
(10, 'CodeCrafters'),
(11, 'DevDynamos'),
(12, 'ByteBuilders'),
(13, 'LogicLords'),
(14, 'SyntaxSquad');

-- --------------------------------------------------------

--
-- Estrutura para tabela `tb_funcionario`
--

CREATE TABLE `tb_funcionario` (
  `id_funcionario` int(11) NOT NULL,
  `nome` varchar(50) NOT NULL,
  `email` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `tb_funcionario`
--

INSERT INTO `tb_funcionario` (`id_funcionario`, `nome`, `email`) VALUES
(29, 'Clara Mendes', 'clara.mendes@codecrafters.com'),
(30, 'Rafael Silva', 'rafael.silva@devdynamos.com'),
(31, 'Amanda Oliveira', 'amanda.oliveira@bytebuilders.com'),
(36, 'Lucas Almeida', 'lucas.almeida@logiclords.com'),
(37, 'Beatriz Santos', 'beatriz.santos@syntaxsquad.com'),
(38, 'Gustavo Lima', 'gustavo.lima@devdynamos.com'),
(39, 'Juliana Ferreira', 'juliana.ferreira@codecrafters.com'),
(40, 'Thiago Rocha', 'thiago.rocha@bytebuilders.com');

-- --------------------------------------------------------

--
-- Estrutura para tabela `tb_projetos`
--

CREATE TABLE `tb_projetos` (
  `id_projeto` int(11) NOT NULL,
  `nome` varchar(50) NOT NULL,
  `salario` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `tb_projetos`
--

INSERT INTO `tb_projetos` (`id_projeto`, `nome`, `salario`) VALUES
(18, 'Sistema de Gerenciamento Escolar', 8500),
(19, 'Plataforma de E-commerce Inteligente', 12000),
(20, 'Aplicativo de Controle Financeiro Pessoal', 10000),
(21, 'Sistema de Automação Residencial', 9000),
(22, 'Ferramenta de Gestão de Projetos Ágeis', 11500);

-- --------------------------------------------------------

--
-- Estrutura para tabela `tb_projetos_equipes`
--

CREATE TABLE `tb_projetos_equipes` (
  `id_projeto` int(11) NOT NULL,
  `id_equipe` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `tb_projetos_equipes`
--

INSERT INTO `tb_projetos_equipes` (`id_projeto`, `id_equipe`) VALUES
(18, 10),
(19, 11),
(20, 12),
(21, 13),
(22, 14);

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `funcionarios_equipes`
--
ALTER TABLE `funcionarios_equipes`
  ADD PRIMARY KEY (`id_funcionario`,`id_equipe`),
  ADD KEY `id_equipe` (`id_equipe`);

--
-- Índices de tabela `tb_equipe`
--
ALTER TABLE `tb_equipe`
  ADD PRIMARY KEY (`id_equipe`);

--
-- Índices de tabela `tb_funcionario`
--
ALTER TABLE `tb_funcionario`
  ADD PRIMARY KEY (`id_funcionario`);

--
-- Índices de tabela `tb_projetos`
--
ALTER TABLE `tb_projetos`
  ADD PRIMARY KEY (`id_projeto`);

--
-- Índices de tabela `tb_projetos_equipes`
--
ALTER TABLE `tb_projetos_equipes`
  ADD PRIMARY KEY (`id_projeto`,`id_equipe`),
  ADD KEY `id_equipe` (`id_equipe`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `tb_equipe`
--
ALTER TABLE `tb_equipe`
  MODIFY `id_equipe` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT de tabela `tb_funcionario`
--
ALTER TABLE `tb_funcionario`
  MODIFY `id_funcionario` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;

--
-- AUTO_INCREMENT de tabela `tb_projetos`
--
ALTER TABLE `tb_projetos`
  MODIFY `id_projeto` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- Restrições para tabelas despejadas
--

--
-- Restrições para tabelas `funcionarios_equipes`
--
ALTER TABLE `funcionarios_equipes`
  ADD CONSTRAINT `funcionarios_equipes_ibfk_1` FOREIGN KEY (`id_funcionario`) REFERENCES `tb_funcionario` (`id_funcionario`) ON DELETE CASCADE,
  ADD CONSTRAINT `funcionarios_equipes_ibfk_2` FOREIGN KEY (`id_equipe`) REFERENCES `tb_equipe` (`id_equipe`) ON DELETE CASCADE;

--
-- Restrições para tabelas `tb_projetos_equipes`
--
ALTER TABLE `tb_projetos_equipes`
  ADD CONSTRAINT `tb_projetos_equipes_ibfk_1` FOREIGN KEY (`id_projeto`) REFERENCES `tb_projetos` (`id_projeto`) ON DELETE CASCADE,
  ADD CONSTRAINT `tb_projetos_equipes_ibfk_2` FOREIGN KEY (`id_equipe`) REFERENCES `tb_equipe` (`id_equipe`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
