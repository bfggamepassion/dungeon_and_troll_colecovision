; NES --> 256x224
; .pp coleco --> 256x192

imageSource$ = "./munitions.bmp"
fileDest$ = "./global.txt"
pos = 0

; VERSION 3.0 avec création du NAME
;----------------------------------------
;-- Convertit un octer en chaine HEXA  --
;----------------------------------------
Function Convert2Hexa$(nombre)

resultat$ = ""
bas$ = ""
haut$ = ""

bas = nombre And 15
haut = nombre And 240


If bas=0 Then
 ba$="0"
End If
If bas=1 Then
 bas$="1"
End If
If bas=2 Then
 bas$="2"
End If

If bas=3 Then
 bas$="3"
End If

If bas=4 Then
 bas$="4"
End If

If bas=5 Then
 bas$="5"
End If

If bas=6 Then
 bas$="6"
End If

If bas=7 Then
 bas$="7"
End If

If bas=8 Then
 bas$="8"
End If

If bas=9 Then
 bas$="9"
End If

If bas=10 Then
 bas$="A"
End If

If bas=11 Then
 bas$="B"
End If

If bas=12 Then
 bas$="C"
End If

If bas=13 Then
 bas$="D"
End If

If bas=14 Then
 bas$="E"
End If

If bas=15 Then
 bas$="F"
End If


If haut=0 Then
 haut$="0"
End If
If haut=16 Then
 haut$="1"
End If
If haut=32 Then
 haut$="2"
End If

If haut=48 Then
 haut$="3"
End If

If haut=64 Then
 haut$="4"
End If

If haut=80 Then
 haut$="5"
End If

If haut=96 Then
 haut$="6"
End If

If haut=112 Then
 haut$="7"
End If

If haut=128 Then
 haut$="8"
End If

If haut=144 Then
 haut$="9"
End If

If haut=160 Then
 haut$="A"
End If

If haut=176 Then
 haut$="B"
End If

If haut=192 Then
 haut$="C"
End If

If haut=208 Then
 haut$="D"
End If

If haut=224 Then
 haut$="E"
End If

If haut=240 Then
 haut$="F"
End If

res$ = haut$ + bas$ 
Return res$
End Function

;-------------------------------------------------
;--- Retourne la couleur simplifiée d'un pixel ---
;-------------------------------------------------
Function returnPixelColor(pix)
 
res = 0
If pix=-16777216 Then 
	res = 1 
End If
If pix=-14563262 Then 
	res = 2 
End If
If pix=-10560392 Then 
	res = 3 
End If
If pix=-11250195 Then 
	res = 4 
End If
If pix=-8554756  Then 
	res = 5 
End If
If pix=-2862515  Then 
	res = 6 
End If
If pix=-12391435 Then 
	res = 7 
End If
If pix=-240300   Then 
	res = 8 
End If
If pix=-34440    Then 
	res = 9 
End If
If pix=-2834092  Then 
	res = 10 
End If
If pix=-1651072  Then 
	res = 11 
End If
If pix=-14569413 Then 
	res = 12 
End If
If pix=-3580998  Then 
	res = 13 
End If
If pix=-3355444  Then 
	res = 14 
End If
If pix=-1        Then 
	res = 15 
End If

Return res
End Function


;-------------------------------------------------
;------------------ MAIN -------------------------
;-------------------------------------------------
Graphics 640,480,16

; Load and draw an image on to the screen - can be anything
pic=LoadImage(imageSource$)
DrawImage pic,0,0 

; Initialise an array big enough to fit all the color information of the screen
Dim pix(256,192)
Dim pattern(7680,8)
Dim col(7680,8)
Dim name(32,24)

Dim patdef(2048,8)
Dim coldef(2048,8)

For x=0 To x=255
	For y=0 To 8
		patdef(x,y)=0
		coldef(x,y)=0
	Next
Next

For x=0 To 31
 For y=0 To 23
	name(x,y)=0
 Next
Next 

; Use ReadPixel to get all the color information of the screen
For y=0 To 191
For x=0 To 255

	pix(x,y)=ReadPixel(x,y)

Next
Next
Cls
p8x=0
p8y=0
CurrentPix=0
ValeurLigne=0
caractereCourant = pos
ligneCourante = 0
namex=0
; On va parcourir le buffer de pixel de 8 en 8
While p8x<256
	p8y=0
	namey=0
	While p8y<191
		; On est positionné sur le caractère
		ligneCourante = 0
		For y=p8y To p8y+7
			; Premier pixel de la ligne du caractere
			premierPixel = returnPixelColor(pix(p8x,y))
			CouleurHaute = returnPixelColor(pix(p8x,y))
			CouleurBasse = 0
			valeurLigne = 0
			CurrentPix =0
			For x=p8x To P8x+7
				pixelCourant = returnPixelColor(pix(x,y))
				If pixelCourant = premierPixel  Then
					If CurrentPix = 0 Then
						valeurLigne = valeurLigne + 128
					End If
					If CurrentPix = 1 Then
						valeurLigne = valeurLigne + 64
					End If
					If CurrentPix = 2 Then
						valeurLigne = valeurLigne + 32
					End If
					If CurrentPix = 3 Then
						valeurLigne = valeurLigne + 16
					End If
					If CurrentPix = 4 Then
						valeurLigne = valeurLigne + 8
					End If
					If CurrentPix = 5 Then
						valeurLigne = valeurLigne + 4
					End If
					If CurrentPix = 6 Then
						valeurLigne = valeurLigne + 2
					End If
					If CurrentPix = 7 Then
						valeurLigne = valeurLigne + 1
					End If	
				End If
				If PixelCourant <> premierPixel
					CouleurBasse = pixelCourant
				End If
				
				CurrentPix = CurrentPix + 1
			Next
			; La ligne est calculée
			pattern(caractereCourant ,ligneCourante) = valeurLigne
			couleurAStocker = CouleurHaute Shl 4
			couleurAStocker = CouleurAStocker + CouleurBasse
			col(caractereCourant ,ligneCourante) = couleurAStocker
			ligneCourante = ligneCourante+1
		Next
		name(namex,namey) = caractereCourant
		caractereCourant = caractereCourant +1
		p8y=p8y+8
		namey=namey+1
	Wend	
	p8x=p8x+8
	namex=namex+1
Wend

; On va recopier uniquement les TILES UNIQUES !!

dest=pos

For TileCouranteSource=0 To 7680
	; Si tc n'est pas dans la zone définitive
	; on le copie dedans
	lp0 = pattern(TileCouranteSource,0)
	lp1 = pattern(TileCouranteSource,1)
	lp2 = pattern(TileCouranteSource,2)
	lp3 = pattern(TileCouranteSource,3)
	lp4 = pattern(TileCouranteSource,4)
	lp5 = pattern(TileCouranteSource,5)
	lp6 = pattern(TileCouranteSource,6)
	lp7 = pattern(TileCouranteSource,7)

	lc0 = col(TileCouranteSource,0)
	lc1 = col(TileCouranteSource,1)
	lc2 = col(TileCouranteSource,2)
	lc3 = col(TileCouranteSource,3)
	lc4 = col(TileCouranteSource,4)
	lc5 = col(TileCouranteSource,5)
	lc6 = col(TileCouranteSource,6)
	lc7 = col(TileCouranteSource,7)

	trouve = 0
	For d=0 To 255
		ldp0 = patdef(d,0)
		ldp1 = patdef(d,1)
		ldp2 = patdef(d,2)
		ldp3 = patdef(d,3)
		ldp4 = patdef(d,4)
		ldp5 = patdef(d,5)
		ldp6 = patdef(d,6)
		ldp7 = patdef(d,7)

		ldc0 = coldef(d,0)
		ldc1 = coldef(d,1)
		ldc2 = coldef(d,2)
		ldc3 = coldef(d,3)
		ldc4 = coldef(d,4)
		ldc5 = coldef(d,5)
		ldc6 = coldef(d,6)
		ldc7 = coldef(d,7)
		
		If ldp0=lp0 And ldp1=lp1 And ldp2=lp2 And ldp3=lp3 And ldp4=lp4 And ldp5=lp5 And ldp6=lp6 And ldp7=lp7 And ldc0=lc0 And ldc1=lc1 And ldc2=lc2 And ldc3=lc3 And ldc4=lc4 And ldc5=lc5 And ldc6=lc6 And ldc7=lc7 And trouve=0 Then
			trouve=1
			switch = d
		End If
	Next
	
	If trouve = 0
	
		patdef(dest,0) = lp0
		patdef(dest,1) = lp1
		patdef(dest,2) = lp2
		patdef(dest,3) = lp3
		patdef(dest,4) = lp4
		patdef(dest,5) = lp5
		patdef(dest,6) = lp6
		patdef(dest,7) = lp7

		coldef(dest,0) = lc0
		coldef(dest,1) = lc1
		coldef(dest,2) = lc2
		coldef(dest,3) = lc3
		coldef(dest,4) = lc4
		coldef(dest,5) = lc5
		coldef(dest,6) = lc6
		coldef(dest,7) = lc7
		
		switch = dest
		
		dest=dest+1
	
	End If
	
	For ppx=0 To 31
		For ppy=0 To 23
			If name(ppx,ppy)=TileCouranteSource Then
				name(ppx,ppy) = switch
			End If
		Next
	Next
	
Next

;----------------------------------------------------------
;---- ECRITURE EN FICHIER ---------------------------------
;----------------------------------------------------------

;fileout = WriteFile("i:/ColecoTileConverter/pattern.txt")
fileout = WriteFile(fileDest$)

pat$ = ""
pat$ = pat$ + Chr$(13) + Chr$(10) + "NAME    DB      "
;fileout = WriteFile("i:/ColecoTileConverter/name.txt")

cpt=0
For Y=0 To 23
	For x=0 To 31
		res$ = Convert2Hexa(name(x,y))
		pat$ = pat$ + "$" + res$
		If cpt<>15 Then
			pat$=pat$ + ","
		End If
		cpt = cpt +1
		If cpt=16 Then
			pat$=pat$ + Chr$(13) + Chr$(10) + "        DB      "
			cpt=0
		End If
	Next
Next


cptlig=0

pat$ = pat$ + Chr$(13) + Chr$(10) + "PATTERN DB      "

For car=0 To 255
	For ligne=0 To 7
		res$ = Convert2Hexa(patdef(car,ligne))
		pat$ = pat$ + "$" + res$  
		If ligne<7  Then
			pat$ = pat$ + ","
		End If
		If Ligne=7 And cptlig=0
			pat$ = pat$ + ","
		End If
	Next
	cptlig= cptlig + 1
	If cptlig=2 Then
		pat$=pat$ + Chr$(13) + Chr$(10) + "        DB      "
		cptlig=0
	End If
Next

;WriteString( fileout, pat$ )

;CloseFile( fileout )


;fileout = WriteFile("i:/ColecoTileConverter/color.txt")

cptlig=0
;pat$ = ""
pat$ = pat$ + Chr$(13) + Chr$(10) + "MCOLOR  DB      "

For car=0 To 255
	For ligne=0 To 7
		res$ = Convert2Hexa(coldef(car,ligne))
		pat$ = pat$ + "$" + res$  
		If ligne<7  Then
			pat$ = pat$ + ","
		End If
		If Ligne=7 And cptlig=0
			pat$ = pat$ + ","
		End If
	Next
	cptlig= cptlig + 1
	If cptlig=2 Then
		pat$=pat$ + Chr$(13) + Chr$(10) + "        DB      "
		cptlig=0
	End If	
Next

;WriteString( fileout, pat$ )

;CloseFile( fileout )

WriteString( fileout, pat$ )

CloseFile( fileout )