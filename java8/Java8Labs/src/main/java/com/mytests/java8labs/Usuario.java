package com.mytests.java8labs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author t3276780
 */
public class Usuario {
    private String nome;
    private int pontos;
    private boolean moderador;

    public Usuario(String nome, int pontos) {
        this.nome = nome;
        this.pontos = pontos;
        this.moderador = false;
    }

    public Usuario(String nome, int pontos, boolean moderador) {
        this.nome = nome;
        this.pontos = pontos;
        this.moderador = moderador;
    }

    public void tornaModerador() {
        this.moderador = true;
    }

    public String getNome() {
        return nome;
    }

    public int getPontos() {
        return pontos;
    }

    public boolean isModerador() {
        return moderador;
    }

    @Override
    public String toString() {
        return "Usuario{" + "nome=" + nome + ", pontos=" + pontos + ", moderador=" + moderador + '}';
    }
    
    public static List<Usuario> criaListaUsuarios() {
        Usuario user1 = new Usuario("Paulo Silveira", 150);
        Usuario user2 = new Usuario("Rodrigo Turini", 120);
        Usuario user3 = new Usuario("Guilherme Silveira", 190);
        List<Usuario> usuarios = new ArrayList<>(Arrays.asList(user1, user2, user3));
        return usuarios;
    }

}
