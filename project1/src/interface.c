/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_fenetre_ajouter (void)
{
  GtkWidget *fenetre_ajouter;
  GtkWidget *fixed1;
  GtkWidget *entryNom;
  GtkWidget *entryPrenom;
  GtkWidget *entryCin;
  GtkWidget *entryDate;
  GtkWidget *entryAdresse;
  GtkWidget *buttonAfficher;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label7;
  GtkWidget *buttonAjouter;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label8;
  GtkWidget *Cin;
  GtkWidget *Adresse;
  GtkWidget *Prenom;
  GtkWidget *Date;
  GtkWidget *Nom;

  fenetre_ajouter = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (fenetre_ajouter), _("Ajouter"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (fenetre_ajouter), fixed1);

  entryNom = gtk_entry_new ();
  gtk_widget_show (entryNom);
  gtk_fixed_put (GTK_FIXED (fixed1), entryNom, 144, 56);
  gtk_widget_set_size_request (entryNom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryNom), 8226);

  entryPrenom = gtk_entry_new ();
  gtk_widget_show (entryPrenom);
  gtk_fixed_put (GTK_FIXED (fixed1), entryPrenom, 144, 136);
  gtk_widget_set_size_request (entryPrenom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryPrenom), 8226);

  entryCin = gtk_entry_new ();
  gtk_widget_show (entryCin);
  gtk_fixed_put (GTK_FIXED (fixed1), entryCin, 144, 216);
  gtk_widget_set_size_request (entryCin, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryCin), 8226);

  entryDate = gtk_entry_new ();
  gtk_widget_show (entryDate);
  gtk_fixed_put (GTK_FIXED (fixed1), entryDate, 512, 56);
  gtk_widget_set_size_request (entryDate, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryDate), 8226);

  entryAdresse = gtk_entry_new ();
  gtk_widget_show (entryAdresse);
  gtk_fixed_put (GTK_FIXED (fixed1), entryAdresse, 512, 136);
  gtk_widget_set_size_request (entryAdresse, 161, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryAdresse), 8226);

  buttonAfficher = gtk_button_new ();
  gtk_widget_show (buttonAfficher);
  gtk_fixed_put (GTK_FIXED (fixed1), buttonAfficher, 544, 296);
  gtk_widget_set_size_request (buttonAfficher, 96, 29);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (buttonAfficher), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-go-forward", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label7 = gtk_label_new_with_mnemonic (_("afficher"));
  gtk_widget_show (label7);
  gtk_box_pack_start (GTK_BOX (hbox2), label7, FALSE, FALSE, 0);

  buttonAjouter = gtk_button_new ();
  gtk_widget_show (buttonAjouter);
  gtk_fixed_put (GTK_FIXED (fixed1), buttonAjouter, 160, 296);
  gtk_widget_set_size_request (buttonAjouter, 96, 29);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (buttonAjouter), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label8 = gtk_label_new_with_mnemonic (_("ajouter"));
  gtk_widget_show (label8);
  gtk_box_pack_start (GTK_BOX (hbox3), label8, FALSE, FALSE, 0);

  Cin = gtk_label_new (_("cin"));
  gtk_widget_show (Cin);
  gtk_fixed_put (GTK_FIXED (fixed1), Cin, 64, 224);
  gtk_widget_set_size_request (Cin, 72, 17);

  Adresse = gtk_label_new (_("adresse"));
  gtk_widget_show (Adresse);
  gtk_fixed_put (GTK_FIXED (fixed1), Adresse, 400, 144);
  gtk_widget_set_size_request (Adresse, 104, 17);

  Prenom = gtk_label_new (_("prenom"));
  gtk_widget_show (Prenom);
  gtk_fixed_put (GTK_FIXED (fixed1), Prenom, 56, 144);
  gtk_widget_set_size_request (Prenom, 88, 17);

  Date = gtk_label_new (_("date de naissance"));
  gtk_widget_show (Date);
  gtk_fixed_put (GTK_FIXED (fixed1), Date, 368, 58);
  gtk_widget_set_size_request (Date, 144, 16);

  Nom = gtk_label_new (_("nom"));
  gtk_widget_show (Nom);
  gtk_fixed_put (GTK_FIXED (fixed1), Nom, 56, 56);
  gtk_widget_set_size_request (Nom, 96, 25);
  gtk_misc_set_padding (GTK_MISC (Nom), 5, 0);

  g_signal_connect ((gpointer) buttonAfficher, "clicked",
                    G_CALLBACK (on_buttonAfficher_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonAjouter, "clicked",
                    G_CALLBACK (on_buttonAjouter_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (fenetre_ajouter, fenetre_ajouter, "fenetre_ajouter");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, entryNom, "entryNom");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, entryPrenom, "entryPrenom");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, entryCin, "entryCin");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, entryDate, "entryDate");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, entryAdresse, "entryAdresse");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, buttonAfficher, "buttonAfficher");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, image2, "image2");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, label7, "label7");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, buttonAjouter, "buttonAjouter");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, image3, "image3");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, label8, "label8");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, Cin, "Cin");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, Adresse, "Adresse");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, Prenom, "Prenom");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, Date, "Date");
  GLADE_HOOKUP_OBJECT (fenetre_ajouter, Nom, "Nom");

  return fenetre_ajouter;
}

GtkWidget*
create_fenetre_afficher (void)
{
  GtkWidget *fenetre_afficher;
  GtkWidget *fixed2;
  GtkWidget *treeview1;
  GtkWidget *buttonRetourner;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label9;

  fenetre_afficher = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (fenetre_afficher), _("Afficher"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (fenetre_afficher), fixed2);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed2), treeview1, 160, 24);
  gtk_widget_set_size_request (treeview1, 1000, 400);

  buttonRetourner = gtk_button_new ();
  gtk_widget_show (buttonRetourner);
  gtk_fixed_put (GTK_FIXED (fixed2), buttonRetourner, 592, 488);
  gtk_widget_set_size_request (buttonRetourner, 112, 32);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (buttonRetourner), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label9 = gtk_label_new_with_mnemonic (_("retourner"));
  gtk_widget_show (label9);
  gtk_box_pack_start (GTK_BOX (hbox4), label9, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) treeview1, "row_activated",
                    G_CALLBACK (on_treeview1_row_activated),
                    NULL);
  g_signal_connect ((gpointer) buttonRetourner, "clicked",
                    G_CALLBACK (on_buttonRetourner_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (fenetre_afficher, fenetre_afficher, "fenetre_afficher");
  GLADE_HOOKUP_OBJECT (fenetre_afficher, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (fenetre_afficher, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (fenetre_afficher, buttonRetourner, "buttonRetourner");
  GLADE_HOOKUP_OBJECT (fenetre_afficher, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (fenetre_afficher, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (fenetre_afficher, image4, "image4");
  GLADE_HOOKUP_OBJECT (fenetre_afficher, label9, "label9");

  return fenetre_afficher;
}

